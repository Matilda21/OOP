#pragma once

#include <memory>

#include "reform_manager.h"

class ReformManagerCreator
{
    public:
        ReformManagerCreator() = default;
        std::shared_ptr<ReformManager> get_manager();
        ~ReformManagerCreator() = default;

    private:
        std::shared_ptr<ReformManager> manager;
        void create_instance();


};
