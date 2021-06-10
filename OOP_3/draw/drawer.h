#ifndef DRAWER_H
#define DRAWER_H

#include "ui_mainwindow.h"
#include "./object/point.hpp"

class BaseDrawer
{
    public:
        BaseDrawer() = default;
        virtual ~BaseDrawer() = default;
        virtual void draw_line(const Point<double> &point1, const Point<double> &point2) = 0;
        virtual void clean_scene() = 0;
        virtual void set_draw_offset(const Point<double> &offset){draw_offset = offset;};
    protected:
        Point<double> draw_offset;
    
};

class QtDrawer : public BaseDrawer
{
    public:
        QtDrawer();
        QtDrawer(QGraphicsScene *_scene);
        QtDrawer(const QtDrawer &drawer);

        virtual void draw_line(const Point<double> &point1, const Point<double> &point2) override;
        virtual void clean_scene() override; 

    private : 
         QGraphicsScene *scene;
};

#endif
