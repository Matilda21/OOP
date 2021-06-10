#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

#include <string>
#include "./object/model.h"
#include "./object/camera.h"
#include "./managers/scene_manager_creator.h"
#include "./managers/reform_manager_creator.h"
#include "./managers/draw_manager_creator.h"
#include "./managers/load_manager_creator.h"
#include <QDebug>
#include "exceptions/ui_exceptions.h"

class BaseCommand
{
    public:
        BaseCommand() = default;
        virtual ~BaseCommand() = default;
        virtual void execute() = 0;

    private:
};

class MoveModel : public BaseCommand
{
    public:
        MoveModel() = delete;
        MoveModel(const double x, const double y, const double z, const size_t model_index)
        {
            this->_x = x;
            this->_y = y;
            this->_z = z;
            this->index = model_index;

        }
        virtual ~MoveModel() = default;
        virtual void execute() override
        {
            qDebug() << "move model move" << this->_x << this->_y << this->_z;
            Point<double> move(this->_x, this->_y, this->_z);
            Point<double> scale(1, 1, 1);
            Point<double> turn(0, 0, 0);

            if (this->index > SceneManagerCreator().get_manager()->get_scene()->get_models().getSize() - 1)
                throw obj_out_of_range_exception();

            std::shared_ptr<Object> model = SceneManagerCreator().get_manager()->get_scene()->get_models().at(this->index);
            ReformManagerCreator().get_manager()->reform(model, move, scale, turn);
        }

    private:

        size_t index;
        double _x;
        double _y;
        double _z;
};

class ScaleModel : public BaseCommand
{
    public:
        ScaleModel() = delete;
        ScaleModel(const double x, const double y, const double z, const size_t model_index)
        {
            this->_x = x;
            this->_y = y;
            this->_z = z;
            this->index = model_index;

        }
        virtual ~ScaleModel() = default;
        virtual void execute() override
        {
            if (this->index > SceneManagerCreator().get_manager()->get_scene()->get_models().getSize() - 1)
                throw obj_out_of_range_exception();

            Point<double> move(0, 0, 0);
            Point<double> scale(this->_x, this->_y, this->_z);
            Point<double> turn(0, 0, 0);
            std::shared_ptr<Object> model = SceneManagerCreator().get_manager()->get_scene()->get_models().at(this->index);
            ReformManagerCreator().get_manager()->reform(model, move, scale, turn);

        }

    private:

        size_t index;
        double _x;
        double _y;
        double _z;
};

class TurnModel : public BaseCommand
{
    public:
        TurnModel() = delete;
        TurnModel(const double x, const double y, const double z, const size_t model_index)
        {
            this->_x = x;
            this->_y = y;
            this->_z = z;
            this->index = model_index;

        }
        virtual ~TurnModel() = default;
        virtual void execute() override
        {
            if (this->index > SceneManagerCreator().get_manager()->get_scene()->get_models().getSize() - 1)
                throw obj_out_of_range_exception();

            Point<double> move(0, 0, 0);
            Point<double> scale(1, 1, 1);
            Point<double> turn(this->_x, this->_y, this->_z);
            std::shared_ptr<Object> model = SceneManagerCreator().get_manager()->get_scene()->get_models().at(this->index);
            ReformManagerCreator().get_manager()->reform(model, move, scale, turn);

        }

    private:

        size_t index;
        double _x;
        double _y;
        double _z;
};

class ReformModel : public BaseCommand
{
    public:
        ReformModel() = delete;
        ReformModel(size_t model_ind, const Point<double> &move, const Point<double> &scale, const Point<double> &turn)
        {
            this->_model_ind = model_ind;
            this->_move = move;
            this->_scale = scale;
            this->_turn = turn;

        }
        virtual ~ReformModel() = default;
        virtual void execute() override
        {
            if (this->_model_ind > SceneManagerCreator().get_manager()->get_scene()->get_models().getSize() - 1)
                throw obj_out_of_range_exception();

            std::shared_ptr<Object> model = SceneManagerCreator().get_manager()->get_scene()->get_models().at(this->_model_ind);
            ReformManagerCreator().get_manager()->reform(model, this->_move, this->_scale, this->_turn);
        }
    private:
        size_t _model_ind;
        Point<double> _move;
        Point<double> _scale;
        Point<double> _turn;
};

class LoadModel : public BaseCommand
{
    public:
        LoadModel() = delete;
        LoadModel(const std::string &filename)
        {
            this->_filename = filename;

        }
        virtual ~LoadModel() = default;
        virtual void execute() override
        {
            std::shared_ptr<LoadManager> load_manager = LoadManagerCreator().get_manager();
            std::shared_ptr<Object> model = load_manager->load_model(this->_filename);

            SceneManagerCreator().get_manager()->get_scene()->add_model(model);
        }

    private:
        std::string _filename;
};

class LoadScene : public BaseCommand
{
    public:
        LoadScene() = delete;
        LoadScene(const std::string &filename)
        {
            this->_filename = filename;

        };
        virtual ~LoadScene() = default;
        virtual void execute() override
        {
            std::shared_ptr<LoadManager> load_manager = LoadManagerCreator().get_manager();
            std::shared_ptr<Scene> scene = load_manager->load_scene(this->_filename);
            qDebug() << "loaded scene";
            SceneManagerCreator().get_manager()->set_scene(scene);
            qDebug() << "seted scene";
        };
    private:
        std::string _filename;
};

class RemoveModel : public BaseCommand
{
    public:
        RemoveModel() = delete;
        RemoveModel(const size_t index)
        {
            this->_index = index;

        };
        virtual ~RemoveModel() = default;
        virtual void execute() override
        {
            if (this->_index > SceneManagerCreator().get_manager()->get_scene()->get_models().getSize() - 1)
                throw obj_out_of_range_exception();

            SceneManagerCreator().get_manager()->get_scene()->remove_model(this->_index);
        };
    private:
        size_t _index;
};

class ToCamera : public BaseCommand
{
    public:
        ToCamera() = delete;
        ToCamera(const size_t index)
        {
            this->_index = index - 1;
        };
        virtual ~ToCamera() = default;
        virtual void execute() override
        {
            if (this->_index > SceneManagerCreator().get_manager()->get_scene()->get_cameras().getSize() - 1)
                throw obj_out_of_range_exception();

            SceneManagerCreator().get_manager()->set_camera(this->_index);
        };
    private:
        size_t _index;
};


class AddCamera : public BaseCommand
{
    public:
        AddCamera(const double x, const double y, const double z)
        {
            this->_x = x;
            this->_y = y;
            this->_z = z;
        };
        virtual ~AddCamera() = default;
        virtual void execute() override
        {
            Point<double> camera_pos(this->_x, this->_y, this->_z);
            std::shared_ptr<Camera> new_camera = std::shared_ptr<Camera>(new Camera(camera_pos));
            SceneManagerCreator().get_manager()->get_scene()->add_camera(new_camera);
            size_t num = SceneManagerCreator().get_manager()->get_scene()->get_cameras().getSize() - 1;
            qDebug() << "num of cameras:" << num + 1;
            SceneManagerCreator().get_manager()->set_camera(num);
        };
    private:
        double _x;
        double _y;
        double _z;
};

class LoadCamera : public BaseCommand
{
    public:
        LoadCamera(const std::string &filename)
        {
            this->_filename = filename;
        };
        virtual ~LoadCamera() = default;
        virtual void execute() override
        {
            std::shared_ptr<LoadManager> load_manager = LoadManagerCreator().get_manager();
            std::shared_ptr<Object> camera = load_manager->load_camera(this->_filename);
            SceneManagerCreator().get_manager()->get_scene()->add_camera(camera);
            size_t num = SceneManagerCreator().get_manager()->get_scene()->get_cameras().getSize() - 1;
            qDebug() << "num of cameras:" << num + 1;
            SceneManagerCreator().get_manager()->set_camera(num);
        };
    private:
        std::string _filename;
};

class RemoveCamera : public BaseCommand
{
    public:
        RemoveCamera() = delete;
        RemoveCamera(const size_t index)
        {
            this->_index = index;

        };
        virtual ~RemoveCamera() = default;
        virtual void execute() override
        {
            if (this->_index > SceneManagerCreator().get_manager()->get_scene()->get_cameras().getSize() - 1)
                throw obj_out_of_range_exception();

            SceneManagerCreator().get_manager()->get_scene()->remove_camera(this->_index);
            size_t num = SceneManagerCreator().get_manager()->get_scene()->get_cameras().getSize() - 1;
            qDebug() << "num of cameras:" << num + 1;
            SceneManagerCreator().get_manager()->set_camera(num);
        };
    private:
        size_t _index;
};

class DrawScene : public BaseCommand
{
    public:
        DrawScene() = delete;
        DrawScene(std::shared_ptr <BaseDrawer> drawer)
        {
            this->_drawer = drawer;

        };
        virtual ~DrawScene() = default;
        virtual void execute() override
        {
            auto draw_manager = DrawManagerCreator().get_manager(this->_drawer);
            auto scene_manager = SceneManagerCreator().get_manager();

            this->_drawer->clean_scene();
            //draw_manager->set_drawer(this->_drawer);
            draw_manager->set_camera(scene_manager->get_camera());
            draw_manager->draw(scene_manager->get_scene()->get_composite());
            //scene_manager->get_scene()->get_composite()->accept(draw_manager);

        };
    private:
        std::shared_ptr <BaseDrawer> _drawer;
        std::shared_ptr <BaseVisitor> _draw_visitor;
};

class MoveCamera : public BaseCommand
{
    public:
        MoveCamera() = delete;
        MoveCamera(const double dx, const double dy)
        {
            this->_camera_index = SceneManagerCreator().get_manager()->get_scene()->get_cameras().getSize() - 1;
            this->_dx = dx;
            this->_dy = dy;
        };
        virtual ~MoveCamera() = default;
        virtual void execute() override
        {
            if (this->_camera_index > SceneManagerCreator().get_manager()->get_scene()->get_cameras().getSize() - 1)
                throw obj_out_of_range_exception();

            auto camera = SceneManagerCreator().get_manager()->get_scene()->get_cameras().at(this->_camera_index);
            Point<double> point_move(this->_dx, this->_dy, 0);
            Point<double> point(0, 0, 0);
            ReformManagerCreator().get_manager()->reform(camera, point_move, point, point);
        };
    private:
        size_t _camera_index;
        double _dx;
        double _dy;
};

#endif
