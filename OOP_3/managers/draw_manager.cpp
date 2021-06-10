#include "draw_manager.h"
#include "iostream"


void DrawManager::draw(const Model &modl)
{
    std::cout << "\nDRAW_MODEL\n";
    this->_visitor->visit(*(this->_camera));
    this->_visitor->visit(modl);
}

void DrawManager::draw(const std::shared_ptr<Composite> &objects)
{

    std::cout << "\nDRAW_COMPOSITE\n";
    this->_visitor->visit(*(this->_camera));
    objects->accept(this->_visitor);

}

void DrawManager::set_visitor(std::shared_ptr<BaseVisitor> visitor)
{
    this->_visitor = visitor;
}

void DrawManager::set_camera(std::shared_ptr<Camera> camera)
{
    this->_camera = camera;
}


