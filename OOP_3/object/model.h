#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include "details.h"
#include "object.h"
//#include "./managers/visitor.h"
#include "link.h"
#include "point.hpp"

class Model : public VisibleObject
{
    friend class DrawVisitor;

    public:
        Model();
        Model(const std::shared_ptr<Details> &details);
        Model(const Model &_model);
        ~Model() = default;

        virtual void accept(std::shared_ptr<BaseVisitor> _visitor) override;
        virtual void reform(const Point<double> &move, const Point<double> &scale, const Point<double> &turn) override;

    private:
        const std::shared_ptr<Details> get_details() const;
        std::shared_ptr<Details> _details;
};


#endif
