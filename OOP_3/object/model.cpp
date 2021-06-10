#include "model.h"

Model::Model()
{
    this->_details = std::shared_ptr<Details>(new Details);//конструктор копирования у shared_ptr
}

Model::Model(const Model &_model)
{
    this->_details = _model._details;//конструктор копирования у shared_ptr
}

Model::Model(const std::shared_ptr<Details> &details)
{
    this->_details = details;//конструктор копирования у shared_ptr
}


const std::shared_ptr<Details> Model::get_details() const
{
    return this->_details;
}


void Model::accept(std::shared_ptr<BaseVisitor> _visitor)
{
    _visitor->visit(*this);
}

void Model::reform(const Point<double> &move, const Point<double> &scale, const Point<double> &turn) 
{
    qDebug() << "Model::reform";
    this->_details->reform(move, scale, turn);
}
