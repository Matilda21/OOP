#ifndef OBJECT_H
#define OBJECT_H

#include <memory>

#include "./managers/visitor.h"
#include "iterator.hpp"
#include "point.hpp"

class BaseVisitor;
class Object;

class Object
{
    public:
        Object() = default;
        virtual ~Object() = default;

        virtual bool add_object(std::shared_ptr<Object> new_obj){return false;};
        virtual bool remove_object(const size_t &index){return false;};
        virtual bool is_composite() const{return false;};
        virtual void accept(std::shared_ptr<BaseVisitor> _visitor){};
        virtual void reform(const Point<double> &move, const Point<double> &scale, const Point<double> &turn){};
        virtual Iterator<std::shared_ptr<Object>> begin() const {return Iterator<std::shared_ptr<Object>>();};
        virtual Iterator<std::shared_ptr<Object>> end() const {return Iterator<std::shared_ptr<Object>>();};
        virtual size_t get_size() const {return 0;};
};

class VisibleObject : public Object
{
    public:
        VisibleObject() = default;
        ~VisibleObject() = default;
        
        virtual bool IsVisible(){return true;};
};

class InvisibleObject : public Object
{
    public:
        InvisibleObject() = default;
        ~InvisibleObject() = default;
        
        virtual bool IsVisible(){return false;};
};

#endif
