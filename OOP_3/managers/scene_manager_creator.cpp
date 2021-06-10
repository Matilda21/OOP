#include "scene_manager_creator.h"

std::shared_ptr<SceneManager> SceneManagerCreator::get_manager()
{
    if (!this->manager)
    {
        this->create_instance();
    }
    return this->manager;
}

void SceneManagerCreator::create_instance()
{
   static std::shared_ptr<SceneManager> manager_instance(new SceneManager());
   this->manager = manager_instance;
}