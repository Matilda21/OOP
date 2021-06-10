#include "visitor.h"
#include "./object/model.h"
#include "./object/camera.h"
class Camera;
class Model;
class Composite;



void DrawVisitor::visit(const Model &modl)
{
    Vector<Link> links = modl.get_details()->get_links();
    Vector<Point<double>> points = modl.get_details()->get_points();
    for (auto link : links)
    {
        this->_drawer->draw_line(points.at(link.getFirst()), points.at(link.getSecond()));
    }

}

void DrawVisitor::visit(const Camera &cam)
{
    this->_drawer->set_draw_offset(cam.get_pos());
}



