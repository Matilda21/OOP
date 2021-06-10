#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H
#include "./managers/base_manager.h"
#include "load_solution.h"
#include "registration_maker.h"
#define MODEL_CFG "model_cfg"
#define CAMERA_CFG "camera_cfg"
#define SCENE_CFG "scene_cfg"

class ConfigManager : public BaseManager
{
    public:
        ConfigManager() = default;
        ~ConfigManager() = default;
        ConfigManager(const ConfigManager &manager) = delete;
        ConfigManager &operator = (const ConfigManager &manager) = delete;

        void registrate()
        {
            LoadRegistrationMaker().registrate(solution);
        }

        std::shared_ptr<BaseLoader> get_model_loader()
        {
            return solution.create(MODEL_CFG)->create_loader();

        }
        std::shared_ptr<BaseLoader> get_camera_loader()
        {
            return solution.create(CAMERA_CFG)->create_loader();
        }
        std::shared_ptr<BaseLoader> get_scene_loader()
        {
            return solution.create(SCENE_CFG)->create_loader();
        }

    private:
        LoadSolution solution;
};

class ConfigManagerCreator
{
    public:
        ConfigManagerCreator() = default;
        std::shared_ptr<ConfigManager> get_manager();
        ~ConfigManagerCreator() = default;

    private:
        std::shared_ptr<ConfigManager> manager;
        void create_instance();


};
#endif // CONFIG_MANAGER_H
