#ifndef BUILDER_H
#define BUILDER_H

#include "./object/model.h"
#include "./object/camera.h"
#include "./object/scene.h"
#include "link.h"
#include "exceptions/load_exceptions.h"
#include "exceptions/model_exceptions.h"

class BaseBuilder
{
    public:
        BaseBuilder() = default;
        ~BaseBuilder() = default;
        virtual void build_point(const Point<double> &pt){};
        virtual void build_link(const Link &new_link){};
        virtual bool is_build() const{return false;};
        virtual void build() = 0;
        virtual std::shared_ptr <Object> get() const = 0;

};

class ModelBuilder : public BaseBuilder
{
    public:
        ModelBuilder();
        ~ModelBuilder() = default;

        virtual bool is_build() const override;
        virtual void build() override;
        virtual void build_point(const Point<double> &pt) override;
        virtual void build_link(const Link &new_link) override;
        virtual std::shared_ptr <Object> get() const override;
     private:
        std::shared_ptr<Details> _details;
};

class CameraBuilder : public BaseBuilder
{
    public:
        CameraBuilder();
        ~CameraBuilder() = default;

        virtual bool is_build() const override;
        virtual void build() override;
        virtual void build_point(const Point<double> &pt) override;

        virtual std::shared_ptr <Object> get() const override;
     private:
        std::shared_ptr<Point<double>> _point;
};

class BaseSceneBuilder
{
    public:
        BaseSceneBuilder();
        ~BaseSceneBuilder() = default;

        virtual bool is_build() const;
        virtual void build();
        virtual void build_point(const Point<double> &new_pt);
        virtual void build_link(const Link &new_link);
        virtual void build_model();
        virtual void build_camera(const double x, const double y, const double z);
        virtual void build_camera(const Point<double> point);
        virtual std::shared_ptr <Scene> get() const;

     private:
        std::shared_ptr<Scene> _scene;
        std::shared_ptr<Details> _details;
};


#endif
