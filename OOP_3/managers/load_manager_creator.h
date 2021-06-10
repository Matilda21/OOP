#pragma once

#include <memory>

#include "load_manager.h"

class LoadManagerCreator
{
    public:
        LoadManagerCreator() = default;
        std::shared_ptr<LoadManager> get_manager();
        ~LoadManagerCreator() = default;


    private:
        std::shared_ptr<LoadManager> manager;
        void create_instance();


};