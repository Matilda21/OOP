#pragma once

#include <memory>
#include "scene_manager.h"

class SceneManagerCreator
{
    public:
        SceneManagerCreator() = default;
        std::shared_ptr<SceneManager> get_manager();
        ~SceneManagerCreator() = default;


    private:
        std::shared_ptr<SceneManager> manager;
        void create_instance();


};
