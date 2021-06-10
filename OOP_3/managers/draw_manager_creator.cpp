#include "draw_manager_creator.h"

std::shared_ptr<DrawManager> DrawManagerCreator::get_manager(const std::shared_ptr<BaseDrawer> drawer)
{
    if (!this->manager)
    {
        this->create_instance(drawer);
    }
    return this->manager;
}

void DrawManagerCreator::create_instance(const std::shared_ptr<BaseDrawer> drawer)
{
   static std::shared_ptr<DrawManager> manager_instance(new DrawManager());
   this->manager = manager_instance;
   this->manager->set_visitor(std::shared_ptr<DrawVisitor>(new DrawVisitor(drawer)));
}
