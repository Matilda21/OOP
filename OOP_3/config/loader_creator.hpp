#ifndef LOADER_CREATOR_HPP
#define LOADER_CREATOR_HPP
#include "./load/loader.h"

class BaseLoaderCreator
{
public:
    BaseLoaderCreator() = default;
    virtual ~BaseLoaderCreator() = default;
    virtual std::shared_ptr<BaseLoader> create_loader() = 0;
};

template <typename TLoader>
class ConLoaderCreator : public BaseLoaderCreator
{
public:
    ConLoaderCreator() = default;
    virtual ~ConLoaderCreator() = default;

    virtual std::shared_ptr<BaseLoader> create_loader() override
    {
            return std::shared_ptr<BaseLoader>(new TLoader());
    }
};


#endif // LOADER_CREATOR_HPP
