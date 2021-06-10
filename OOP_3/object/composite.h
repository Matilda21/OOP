#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"
#include "model.h"
#include "vector.h"
#include "iterator.h"

class Composite : public Object
{
    friend class Scene;
    public:
        Composite();
        Composite(std::shared_ptr<Object> &obj);
        Composite(Vector<std::shared_ptr<Object>> &objs);

        virtual size_t get_size() const override;

        virtual bool add_object(std::shared_ptr<Object> new_obj) override;
        virtual bool remove_object(const size_t &index) override;

        virtual Iterator<std::shared_ptr<Object>> begin() const override;
        virtual Iterator<std::shared_ptr<Object>> end() const override;

        virtual bool is_composite() const override;
        virtual void accept(std::shared_ptr<BaseVisitor> _visitor) override;
        virtual void reform(const Point<double> &move, const Point<double> &scale, const Point<double> &turn) override; 

    private:
        Vector<std::shared_ptr<Object>> &get_objects(){return this->objects;};
        Vector<std::shared_ptr<Object>> objects;   
};

#endif
