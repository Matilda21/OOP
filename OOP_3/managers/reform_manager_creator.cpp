#include "reform_manager_creator.h"

std::shared_ptr<ReformManager> ReformManagerCreator::get_manager()
{
    if (!this->manager)
    {
        this->create_instance();
    }
    return this->manager;
}

void ReformManagerCreator::create_instance()
{
   static std::shared_ptr<ReformManager> manager_instance(new ReformManager());
   this->manager = manager_instance;
}