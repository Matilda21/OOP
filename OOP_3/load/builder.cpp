#include "builder.h"

ModelBuilder::ModelBuilder()
{
    this->_details = nullptr;
}

void ModelBuilder::build()
{
    this->_details = std::shared_ptr<Details>(new Details());

}

bool ModelBuilder::is_build() const
{
    return this->_details != nullptr;

}


void ModelBuilder::build_point(const Point<double> &pt)
{
    if (!is_build())
        throw build_exception();

    this->_details->add_point(pt);
}


void ModelBuilder::build_link(const Link &new_link)
{
    if (!is_build())
        throw build_exception();

    this->_details->add_link(new_link);
}

std::shared_ptr<Object> ModelBuilder::get() const
{
    if (!is_build())
        throw build_exception();

    std::shared_ptr<Model> model = std::shared_ptr<Model>(new Model(this->_details));
    return model;
}


CameraBuilder::CameraBuilder()
{
    this->_point = nullptr;
}


bool CameraBuilder::is_build() const
{
    return this->_point != nullptr;

}


void CameraBuilder::build()
{
    this->_point = std::shared_ptr<Point<double>>(new Point<double>(0,0,0));

}


void CameraBuilder::build_point(const Point<double> &pt)
{
    this->_point->setX(pt.getX());
    this->_point->setY(pt.getY());
    this->_point->setZ(pt.getZ());
}


std::shared_ptr<Object> CameraBuilder::get() const
{
    if (!is_build())
        throw build_exception();

    std::shared_ptr<Camera> camera = std::shared_ptr<Camera>(new Camera(*_point));
    return camera;
}

BaseSceneBuilder::BaseSceneBuilder()
{
    this->_scene = nullptr;
    this->_details = nullptr;
}

bool BaseSceneBuilder::is_build() const
{
    return this->_scene != nullptr;
}


void BaseSceneBuilder::build()
{
    this->_scene = std::shared_ptr<Scene>(new Scene());
    this->_details = std::shared_ptr<Details>(new Details());

} 


void BaseSceneBuilder::build_point(const Point<double> &new_pt)
{
    if (!is_build())
        throw build_exception();

    this->_details->add_point(new_pt);
}


void BaseSceneBuilder::build_link(const Link &new_link)
{
    if (!is_build())
        throw build_exception();

    this->_details->add_link(new_link);
}

void BaseSceneBuilder::build_model()
{
    if (!is_build())
        throw build_exception();

    if (!_details)
        throw build_exception();

    std::shared_ptr<Model> model = std::shared_ptr<Model>(new Model(this->_details));
    this->_details = std::shared_ptr<Details>(new Details());
    this->_scene->add_model(model);

}

void BaseSceneBuilder::build_camera(const double x, const double y, const double z)
{
    if (!is_build())
        throw build_exception();

    Point<double> point(x, y, z);
    std::shared_ptr<Camera> camera = std::shared_ptr<Camera>(new Camera(point));
    this->_scene->add_camera(camera);

}

void BaseSceneBuilder::build_camera(const Point<double> point)
{
    if (!is_build())
        throw build_exception();

    std::shared_ptr<Camera> camera = std::shared_ptr<Camera>(new Camera(point));
    this->_scene->add_camera(camera);

}

std::shared_ptr<Scene> BaseSceneBuilder::get() const
{
    if (!is_build())
        throw build_exception();

    return this->_scene;
}





