#include "load_manager_creator.h"

std::shared_ptr<LoadManager> LoadManagerCreator::get_manager()
{
    if (!this->manager)
    {
        this->create_instance();
    }
    return this->manager;
}

void LoadManagerCreator::create_instance()
{
   static std::shared_ptr<LoadManager> manager_instance(new LoadManager());
   this->manager = manager_instance;
}