#ifndef REGISTRATION_MAKER_H
#define REGISTRATION_MAKER_H
#include <iostream>
#include "./load/loader.h"
#include "loader_creator.hpp"
#include "load_solution.h"
#include "exceptions/load_exceptions.h"
#include <QDebug>

class  BaseRegistrationMaker
{
     virtual void registrate(LoadSolution &sol) = 0;
};

class LoadRegistrationMaker : public BaseRegistrationMaker
{
    public:
        virtual void registrate(LoadSolution &sol) override
        {
            bool is_registered = sol.registration(0,
              std::shared_ptr<BaseLoaderCreator>(new ConLoaderCreator<FileLoader>()));
            if (!is_registered)
                throw config_exception();


             is_registered = sol.registration(1,
                 std::shared_ptr<BaseLoaderCreator>(new ConLoaderCreator<BaseLoader>()));

              if (!is_registered)
                   throw config_exception();

    }
};

#endif // REGISTRATION_MAKER_H
