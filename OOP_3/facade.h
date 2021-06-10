#ifndef FACADE_H
#define FACADE_H

#include "./load/loader.h"
#include "command.h"
#include "./managers/draw_manager.h"
#include "./managers/scene_manager.h"
#include "./managers/reform_manager.h"
//#include "../scene/scene.h"

class Facade
{
    public:
        static std::shared_ptr<Facade> instance()
        {
            static std::shared_ptr<Facade> facade_instance(new Facade());
            return facade_instance;

        }

        ~Facade() = default;

        void execute(const std::shared_ptr<BaseCommand> &command);


    private:       
        Facade() = default;
        Facade(const Facade &_facade) = delete;
        Facade &operator = (const Facade &_facade) = delete;
};

#endif;
