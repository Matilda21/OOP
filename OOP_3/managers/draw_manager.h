#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include <memory>
#include "./draw/drawer.h"
#include "visitor.h"
#include "base_manager.h"
#include "./object/composite.h"
#include "./object/camera.h"
#include "link.h"


class DrawManager : public BaseManager
{
    public:
        DrawManager() = default;
        ~DrawManager() = default;
        DrawManager(const DrawManager &draw_manager) = delete;
        DrawManager &operator = (const DrawManager &draw_manager) = delete;

        void draw(const Model &modl);
        void draw(const std::shared_ptr<Composite> &objects);

        void set_visitor(std::shared_ptr<BaseVisitor> visitor);
        void set_camera(std::shared_ptr<Camera> camera);

    private:
        std::shared_ptr<BaseVisitor> _visitor;
        std::shared_ptr<Camera> _camera;
};

#endif
