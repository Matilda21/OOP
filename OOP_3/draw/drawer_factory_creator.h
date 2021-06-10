#pragma once
#include "factory.h"

class DrawerFactoryCreator
{
    public:
        static std::unique_ptr<AbstractFactory> createQtFactory()
        {
	        return std::unique_ptr<AbstractFactory>(new QtFactory());
        }
};