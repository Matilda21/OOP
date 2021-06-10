#include "config_manager.h"


std::shared_ptr<ConfigManager> ConfigManagerCreator::get_manager()
{
    if (!this->manager)
    {
        this->create_instance();
    }
    return this->manager;
}

void ConfigManagerCreator::create_instance()
{
   static std::shared_ptr<ConfigManager> manager_instance(new ConfigManager());
   this->manager = manager_instance;
}
