#ifndef REFORM_MANAGER_H
#define REFORM_MANAGER_H

#include "./object/object.h"
#include "base_manager.h"

class ReformManager : BaseManager
{
    public:
        ReformManager() = default;
        ~ReformManager() = default;

        void reform(std::shared_ptr<Object> obj, const Point<double> &move, const Point<double> &scale, const Point<double> &turn);
        void move(std::shared_ptr<Object> obj, double dx, double dy, double dz);
        void scale(std::shared_ptr<Object> obj, double kx, double ky, double kz);
        void turn(std::shared_ptr<Object> obj, double x_ang, double y_ang, double z_ang);
};

#endif
