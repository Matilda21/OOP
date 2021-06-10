#ifndef SCENE_H
#define SCENE_H

#include "composite.h"
#include "camera.h"

class Scene
{
    public:
        Scene();
        ~Scene() = default;

        void add_model(std::shared_ptr<Object> new_model);
        void remove_model(size_t index);

        void add_camera(std::shared_ptr<Object> new_cam);
        void remove_camera(size_t index);

        std::shared_ptr<Composite> get_composite();
        Vector<std::shared_ptr<Object>> get_models();
        Vector<std::shared_ptr<Camera>> get_cameras();

    protected:
       std::shared_ptr<Composite> models;
       Vector<std::shared_ptr<Camera>> cameras;

};
#endif
