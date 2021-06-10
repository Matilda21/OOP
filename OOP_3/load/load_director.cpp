
#include "load_director.h"
#include <iostream>

ModelLoadDirector::ModelLoadDirector()
{
    this->_builder = std::shared_ptr<ModelBuilder>(new ModelBuilder());
}

void ModelLoadDirector::set_loader(const std::shared_ptr <BaseLoader> loader)
{
    this->_loader = loader;
}

std::shared_ptr<Object> ModelLoadDirector::load()
{
    this->_builder->build();
    this->_loader->src_open(this->_filename);

    size_t num_pts = this->_loader->load_number();
    qDebug() << "num_pts" << num_pts;

    for (size_t i = 0; i < num_pts; i++)
    {
        std::shared_ptr<Point <double>> point = std::shared_ptr<Point <double>>(new Point<double>());
        this->_loader->load_point(*point);
        this->_builder->build_point(*point);
    }
    size_t num_lnks = this->_loader->load_number();
    qDebug() << "num_lnks" << num_lnks;

    for (size_t i = 0; i < num_lnks; i++)
    {
        std::shared_ptr<Link> link = std::shared_ptr<Link>(new Link());
        this->_loader->load_link(*link);
        this->_builder->build_link(*link);
    }

    this->_loader->src_close();
    return this->_builder->get();
}


std::shared_ptr<Object> CameraLoadDirector::load()
{
    this->_builder->build();
    this->_loader->src_open(this->_filename);

    std::shared_ptr<Point <double>> point = std::shared_ptr<Point <double>>(new Point<double>());
    this->_loader->load_point(*point);
    this->_builder->build_point(*point);

    this->_loader->src_close();
    return this->_builder->get();
}

CameraLoadDirector::CameraLoadDirector()
{
    this->_builder = std::shared_ptr<CameraBuilder>(new CameraBuilder());
}


void CameraLoadDirector::set_loader(const std::shared_ptr <BaseLoader> loader)
{
    this->_loader = loader;
}

SceneLoadDirector::SceneLoadDirector()
{
    this->_builder = std::shared_ptr<BaseSceneBuilder>(new BaseSceneBuilder);
}

void SceneLoadDirector::set_loader(const std::shared_ptr <BaseLoader> loader)
{
    this->_loader = loader;
}
void SceneLoadDirector::set_builder(const std::shared_ptr <BaseSceneBuilder> builder)
{
    this->_builder = builder;

}

std::shared_ptr<Scene> SceneLoadDirector::load()
{
    this->_builder->build();
    this->_loader->src_open(this->_filename);
    qDebug() << "src_open";
    size_t num_pts, num_lnks;

    size_t num_models = this->_loader->load_number();
    qDebug() << "num_models" << num_models;
    for (size_t j = 0; j < num_models; j++)
    {
        num_pts = this->_loader->load_number();
        qDebug() << "num_pts" << num_pts;

        for (size_t i = 0; i < num_pts; i++)
        {
            std::shared_ptr<Point <double>> point = std::shared_ptr<Point <double>>(new Point<double>());
            this->_loader->load_point(*point);
            this->_builder->build_point(*point);
        }
        num_lnks = this->_loader->load_number();
        qDebug() << "num_lnks" << num_lnks;

        for (size_t i = 0; i < num_lnks; i++)
        {
            std::shared_ptr<Link> link = std::shared_ptr<Link>(new Link());
            this->_loader->load_link(*link);
            this->_builder->build_link(*link);
        }

        this->_builder->build_model();
    }

    size_t num_cameras = this->_loader->load_number();

    qDebug() << "num_cameras" << num_cameras;

    for (size_t j = 0; j < num_cameras; j++)
    {
        std::shared_ptr<Point <double>> point = std::shared_ptr<Point <double>>(new Point<double>());
        this->_loader->load_point(*point);
        this->_builder->build_camera(*point);
    }
    this->_loader->src_close();
    return this->_builder->get();
}
