#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include "./exceptions/load_exceptions.h"
#include "./object/camera.h"
#include "./object/scene.h"
#include "base_manager.h"

class SceneManager : public BaseManager
{
    public:
        SceneManager();
        ~SceneManager() = default;

        void set_scene(std::shared_ptr<Scene> new_scene);

        void set_camera(size_t camera_index);       
        void set_camera(const std::shared_ptr<Camera> camera);

        bool is_camera_set(){return this->cur_camera != nullptr;};

        std::shared_ptr<Scene> get_scene() const;
        std::shared_ptr<Camera> get_camera() const;

        void next_camera();
    private:
        std::shared_ptr<Scene> _scene;
        std::shared_ptr<Camera> cur_camera;
};

#endif
