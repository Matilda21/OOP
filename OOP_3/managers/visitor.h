#ifndef VISITOR_H
#define VISITOR_H
//#include "./object/model.h"
#include "./vector.h"
#include "./object/link.h"
#include "./object/point.hpp"
#include "./draw/drawer.h"

class Camera;
class Model;
class Composite;

class BaseVisitor
{
    public:
        BaseVisitor() = default;
        ~BaseVisitor() = default;
        virtual void visit(const Camera &cam) = 0;
        virtual void visit(const Model &modl) = 0;
        virtual void visit(const Composite &objects) {;};
    
};

class DrawVisitor : public BaseVisitor
{
    public:
        DrawVisitor() = default;
        DrawVisitor(const std::shared_ptr<BaseDrawer> drawer){this->_drawer = drawer;};
        ~DrawVisitor() = default;
        virtual void visit(const Camera &cam) override;
        virtual void visit(const Model &modl) override;
    private:
        std::shared_ptr<BaseDrawer> _drawer;

};


#endif
