#ifndef LOAD_SOLUTION_H
#define LOAD_SOLUTION_H
#include <QDebug>
using namespace std;
# include <iostream>
# include <memory>
# include <map>
#define MODEL_CFG "model_cfg"
#define CAMERA_CFG "camera_cfg"
#define SCENE_CFG "scene_cfg"
#include "loader_creator.hpp"
#include "exceptions/load_exceptions.h"

class LoadSolution
{
public:
    bool registration(size_t id, std::shared_ptr<BaseLoaderCreator> loader_creator)
    {
        return creators.insert(CreatorsMap::value_type(id, loader_creator)).second;
    }

    bool check(size_t id)
    {
    return creators.erase(id) == 1;
    }

    std::shared_ptr<BaseLoaderCreator> create(const std::string &filename)
    {
        std::ifstream file;
        file.open(filename);

        if (!file)
        {
            qDebug() << "файл не открылся: ";
            throw file_open_exception();
        }

        size_t id;

        if (!(file >> id))
            throw file_format_exception();

        qDebug() << "ищем: " << id;
        CreatorsMap::const_iterator it = creators.find(id);

        if (it == creators.end())
        {
            qDebug() << "не найдено: " << id;     
            throw config_exception();
        }

        return std::shared_ptr<BaseLoaderCreator>((it->second));
    }

private:
    using CreatorsMap = map<size_t, std::shared_ptr<BaseLoaderCreator>>;
    CreatorsMap creators;
};

#endif // LOAD_SOLUTION_H
