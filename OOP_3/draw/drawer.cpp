#include "drawer.h"

QtDrawer::QtDrawer()
{
    this->scene = nullptr;

}

QtDrawer::QtDrawer(QGraphicsScene *_scene)
{
    this->scene = _scene;

}

QtDrawer::QtDrawer(const QtDrawer &drawer)
{
    this->scene = drawer.scene;

}

void QtDrawer::draw_line(const Point<double> &point1, const Point<double> &point2) 
{
    this->scene->addLine(point1.getX()-draw_offset.getX(), point1.getY()-draw_offset.getY(),
                         point2.getX()-draw_offset.getX(), point2.getY()-draw_offset.getY());

}

void QtDrawer::clean_scene() 
{
    scene->clear();

}
