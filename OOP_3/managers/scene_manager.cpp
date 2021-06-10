#include "scene_manager.h"

SceneManager::SceneManager()
{
    this->_scene = std::shared_ptr<Scene>(new Scene());
    this->cur_camera = this->_scene->get_cameras().at(0);
}

void SceneManager::set_scene(std::shared_ptr<Scene> new_scene)
{
    this->_scene = new_scene;
}
void SceneManager::set_camera(size_t camera_index)
{
    this->cur_camera = this->_scene->get_cameras().at(camera_index);

    //this->_scene->get_cameras()
}

std::shared_ptr<Scene> SceneManager::get_scene() const
{
    return this->_scene;
}
std::shared_ptr<Camera> SceneManager::get_camera() const
{
    if (this->cur_camera == nullptr)
        throw no_camera_exception();

    return this->cur_camera;
}

void SceneManager::next_camera()
{
    
}
