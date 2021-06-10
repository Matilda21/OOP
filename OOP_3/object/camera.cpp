#include "camera.h"
#include "./managers/visitor.h"

Camera::Camera(const Point<double> &_pos)
{
    this->pos = _pos;
}

void Camera::accept(std::shared_ptr<BaseVisitor> _visitor)
{
    _visitor->visit(*this);
}

void Camera::reform(const Point<double> &move, const Point<double> &scale, const Point<double> &turn) 
{
    this->pos.move(move.getX(), move.getY(), move.getZ());
}

const Point<double> &Camera::get_pos() const
{
    return this->pos;
}

