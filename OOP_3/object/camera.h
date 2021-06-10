#ifndef CAMERA_H
#define CAMERA_H
#include "./managers/draw_manager.h"
#include "object.h"

class Camera: public InvisibleObject
{
    friend class DrawVisitor;
    public:
        Camera() = default;
        Camera(const Point<double> &_pos);
        ~Camera() = default;

        virtual void accept(std::shared_ptr<BaseVisitor> _visitor) override;
        virtual void reform(const Point<double> &move, const Point<double> &scale, const Point<double> &turn) override;
    private:
        const Point<double> &get_pos() const;
        Point<double> pos;
};

#endif
