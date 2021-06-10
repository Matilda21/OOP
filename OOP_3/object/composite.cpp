#include "composite.h"
#include "./managers/visitor.h"

Composite::Composite()
{
    this->objects = Vector<std::shared_ptr<Object>>();
}

Composite::Composite(std::shared_ptr<Object> &obj)
{
    this->objects = Vector<std::shared_ptr<Object>>(obj, 1);
}

Composite::Composite(Vector<std::shared_ptr<Object>> &objs)
{
    this->objects = objs;

}

size_t Composite::get_size() const
{
    return this->objects.getSize();
}

bool Composite::add_object(std::shared_ptr<Object> new_obj) 
{
    this->objects.pushBack(new_obj);
    return true;
}

bool Composite::remove_object(const size_t &index) 
{
    this->objects.remove(index);
    return true;
}

Iterator<std::shared_ptr<Object>> Composite::begin() const
{
    return this->objects.begin();

}

Iterator<std::shared_ptr<Object>> Composite::end() const
{
    return this->objects.end();
}

bool Composite::is_composite() const 
{
    return true;
}

void Composite::accept(std::shared_ptr<BaseVisitor> _visitor)
{
    for (auto obj: this->objects)
    {
        obj->accept(_visitor);
    }
}

void Composite::reform(const Point<double> &move, const Point<double> &scale, const Point<double> &turn) 
{
    for (auto obj : this->objects)
    {
        obj->reform(move, scale, turn);
    }
} 
