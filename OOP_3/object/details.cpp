#include "details.h"

Details::Details(Vector <Point<double>> &pts, Vector<Link> &lnks)
{
    this->points = pts;
    this->links = lnks;
}

void Details::add_point(const Point<double> &pt)
{
    this->points.pushBack(pt);
}

void Details::add_link(const Link &lnk)
{
    this->links.pushBack(lnk);
}

const Vector<Point<double>> &Details::get_points() const
{
    return this->points;
}

const Vector<Link> &Details::get_links() const
{
    return this->links;
}

Point<double> Details::get_center() const
{
    Point<double> center(0, 0, 0);
    for (auto &point : this->points)
    {
        center.move(point.getX(), point.getY(), point.getZ());
    }
    center /= this->points.getSize();

    return center;
}

void Details::reform(const Point<double> &_move, const Point<double> &_scale, const Point<double> &_turn)
{
      Point<double> center = this->get_center();
      qDebug() << "DETAILS" << _move.getX() << _move.getY() << _move.getZ();

      for (auto &pt : points)
      {
        pt.move(_move.getX(), _move.getY(), _move.getZ());
        pt.scale(center, _scale.getX(), _scale.getY(), _scale.getZ());
        pt.turn(center, _turn.getX(), _turn.getY(), _turn.getZ());
      }
}
