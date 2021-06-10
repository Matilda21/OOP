#include "scene.h"
#include "./exceptions/load_exceptions.h"

Scene::Scene()
{
    this->models = std::shared_ptr<Composite>(new Composite());
    this->cameras = Vector<std::shared_ptr<Camera>>();
    std::shared_ptr<Camera> default_cam = std::shared_ptr<Camera>(new Camera());
    this->cameras.pushBack(default_cam);
}

void Scene::add_model(std::shared_ptr<Object> new_model)
{
    this->models->add_object(new_model);
}
void Scene::remove_model(size_t index)
{
    this->models->remove_object(index);
}

void Scene::add_camera(std::shared_ptr<Object> new_cam)
{
    this->cameras.pushBack(std::dynamic_pointer_cast<Camera>(new_cam));
}
void Scene::remove_camera(size_t index)
{
    if (this->cameras.getSize() < 2)
        throw no_camera_exception();

    this->cameras.remove(index);
}

std::shared_ptr<Composite> Scene::get_composite()
{
    return this->models;
}

Vector<std::shared_ptr<Object>> Scene::get_models()
{
    return this->models->get_objects();
}
Vector<std::shared_ptr<Camera>> Scene::get_cameras()
{
    return this->cameras;
}
