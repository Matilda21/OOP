#ifndef DETAILS_H
#define DETAILS_H

#include "vector.h"
#include "iterator.hpp"
#include "link.h"
#include "point.hpp"

class Details
{
    public:
        Details() = default;
        Details(Vector <Point<double>> &pts, Vector<Link> &lnks);

        ~Details() = default;

        void add_point(const Point<double> &pt);
        void add_link(const Link &lnk);

        const Vector<Point<double>> &get_points() const;
        const Vector<Link> &get_links() const;
        Point<double> get_center() const;

        void reform(const Point<double> &_move, const Point<double> &_scale, const Point<double> &_turn);

        

    private:
        Vector<Point<double>> points;
        Vector<Link> links;
        

};

#endif
