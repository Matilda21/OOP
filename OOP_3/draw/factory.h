#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include "drawer.h"

class AbstractFactory
{
public:
    virtual std::unique_ptr<BaseDrawer> create_graphics() = 0;
    virtual void set_scene(QGraphicsScene *scene) = 0;
};

class QtFactory : public AbstractFactory
{
public:
    QtFactory() = default;
    explicit QtFactory(QGraphicsScene *scene)
    {
        this->_scene = scene;
    }

    virtual std::unique_ptr<BaseDrawer> create_graphics() override
    {
        return std::unique_ptr<BaseDrawer> (new QtDrawer(this->_scene));
    }
    virtual void set_scene(QGraphicsScene *scene) override
    {
        this->_scene = scene;
    }
    private:
        QGraphicsScene *_scene;

};

#endif
