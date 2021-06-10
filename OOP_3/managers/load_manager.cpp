#include "load_manager.h"
#include "config/load_solution.h"
#include "config/loader_creator.hpp"
#include "config/config_manager.h"

LoadManager::LoadManager()
{
    this->model_load_director = std::shared_ptr<BaseLoadDirector>(new ModelLoadDirector());
    this->camera_load_director = std::shared_ptr<BaseLoadDirector>(new CameraLoadDirector());
    this->scene_load_director = std::shared_ptr<SceneLoadDirector>(new SceneLoadDirector());
}

std::shared_ptr<Object> LoadManager::load_model(const std::string &filename)
{
    if (model_load_director == nullptr)
        throw no_director_exception();

    std::shared_ptr<BaseLoader> loader = ConfigManagerCreator().get_manager()->get_model_loader();
    this->model_load_director->set_loader(loader);

    this->model_load_director->set_src(filename);
    return this->model_load_director->load();

}

std::shared_ptr<Object> LoadManager::load_camera(const std::string &filename)
{
    if (camera_load_director == nullptr)
        throw no_director_exception();

    std::shared_ptr<BaseLoader> loader = ConfigManagerCreator().get_manager()->get_camera_loader();
    this->camera_load_director->set_loader(loader);

    this->camera_load_director->set_src(filename);
    return this->camera_load_director->load();

}

std::shared_ptr<Scene> LoadManager::load_scene(const std::string &filename)
{
    if (scene_load_director == nullptr)
        throw no_director_exception();

    std::shared_ptr<BaseLoader> loader = ConfigManagerCreator().get_manager()->get_scene_loader();
    this->scene_load_director->set_loader(loader);
    this->scene_load_director->set_src(filename);
    return this->scene_load_director->load();

}
