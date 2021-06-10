#include "reform_manager.h"

void ReformManager::reform(std::shared_ptr<Object> obj, const Point<double> &move, const Point<double> &scale, const Point<double> &turn)
{
    obj->reform(move, scale, turn);
}


void ReformManager::move(std::shared_ptr<Object> obj, double dx, double dy, double dz)
{
    Point<double> move(dx, dy, dz);
    this->reform(obj, move, Point<double>(1, 1, 1), Point<double>(0, 0, 0));
}
void ReformManager::scale(std::shared_ptr<Object> obj, double kx, double ky, double kz)
{
    Point<double> scale(kx, ky, kz);
    this->reform(obj, Point<double>(0, 0, 0), scale, Point<double>(0, 0, 0));

}
void ReformManager::turn(std::shared_ptr<Object> obj, double x_ang, double y_ang, double z_ang)
{
    Point<double> turn(x_ang, y_ang, z_ang);
    this->reform(obj, Point<double>(0, 0, 0), Point<double>(1, 1, 1), turn);
}

