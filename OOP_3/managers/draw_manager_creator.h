#pragma once

#include <memory>
#include "draw_manager.h"

class DrawManagerCreator
{
    public:
        DrawManagerCreator() = default;
        std::shared_ptr<DrawManager> get_manager(const std::shared_ptr<BaseDrawer> drawer);
        ~DrawManagerCreator() = default;
    private:
        std::shared_ptr<DrawManager> manager;
        void create_instance(const std::shared_ptr<BaseDrawer> drawer);


};
