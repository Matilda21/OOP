#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <fstream>

#include "builder.h"
#include "./object/model.h"

class BaseLoader
{
    public:
        BaseLoader() = default;
        virtual ~BaseLoader() = default;
        virtual void src_open(const std::string &srcname) {};
        virtual void src_close() {};
        virtual void load_point(Point<double> &point){};
        virtual void load_link(Link &link){};
        virtual size_t load_number(){};
};


class FileLoader : public BaseLoader
{
    public:
        FileLoader() = default;
        virtual ~FileLoader() = default;
        virtual void src_open(const std::string &srcname) override;
        virtual void src_close() override;
        virtual void load_point(Point<double> &point) override;
        virtual void load_link(Link &link) override;
        virtual size_t load_number() override;
    protected:
        std::ifstream file;
};


#endif
