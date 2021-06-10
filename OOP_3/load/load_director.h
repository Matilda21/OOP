#pragma once

#include <memory>
#include <utility>

#include "builder.h"
#include "loader.h"
#include "./object/point.hpp"

class BaseLoadDirector
{
    public:
        BaseLoadDirector() = default;
        ~BaseLoadDirector() = default;

        virtual void set_src(std::string srcname) = 0;
        virtual void set_loader(const std::shared_ptr <BaseLoader> loader){};
        virtual std::shared_ptr<Object> load() = 0;

};

class ModelLoadDirector : public BaseLoadDirector
{
    public:
        ModelLoadDirector();
        ~ModelLoadDirector() = default;

        virtual std::shared_ptr<Object> load() override;
        virtual void set_loader(const std::shared_ptr <BaseLoader> loader) override;
        virtual void set_src(std::string filename) override {_filename = filename;};

    private:
        std::shared_ptr<BaseLoader> _loader;
        std::shared_ptr<BaseBuilder> _builder;
        std::string _filename;  

};

class CameraLoadDirector : public BaseLoadDirector
{
    public:
        CameraLoadDirector();
        ~CameraLoadDirector() = default;


        virtual std::shared_ptr<Object> load() override;
        virtual void set_loader(const std::shared_ptr <BaseLoader> loader) override;
        virtual void set_src(std::string filename) override {_filename = filename;};

    private:
        std::shared_ptr<BaseLoader> _loader;
        std::shared_ptr<BaseBuilder> _builder;
        std::string _filename;

};

class BaseSceneLoadDirector
{
    public:
        BaseSceneLoadDirector() = default;
        ~BaseSceneLoadDirector() = default;
        virtual void set_src(std::string filename){_filename = filename;};
        virtual void set_loader(const std::shared_ptr <BaseLoader> loader) = 0;
        virtual void set_builder(const std::shared_ptr <BaseSceneBuilder> builder) = 0;
        virtual std::shared_ptr<Scene> load() = 0;
   protected:
        std::string _filename;

};

class SceneLoadDirector : public BaseSceneLoadDirector
{
    public:
        SceneLoadDirector();
        ~SceneLoadDirector() = default;

        virtual std::shared_ptr<Scene> load() override;
        virtual void set_loader(const std::shared_ptr <BaseLoader> loader) override;
        virtual void set_builder(const std::shared_ptr <BaseSceneBuilder> builder) override;

    private:
        std::shared_ptr<BaseLoader> _loader;
        std::shared_ptr<BaseSceneBuilder> _builder;
};
