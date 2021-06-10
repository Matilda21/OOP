#ifndef LOAD_MANAGER_H
#define LOAD_MANAGER_H

#include "./object/object.h"
#include "base_manager.h"
#include "./load/load_director.h"

class LoadManager : BaseManager
{
    public:
        LoadManager();
        ~LoadManager() = default;
        LoadManager(const LoadManager &manager) = delete;
        LoadManager &operator = (const LoadManager &manager) = delete;

        std::shared_ptr<Object> load_model(const std::string &filename);
        std::shared_ptr<Object> load_camera(const std::string &filename);
        std::shared_ptr<Scene> load_scene(const std::string &filename);

    private:
        std::shared_ptr<BaseLoadDirector> model_load_director;
        std::shared_ptr<BaseLoadDirector> camera_load_director;
        std::shared_ptr<SceneLoadDirector> scene_load_director;
};

#endif
