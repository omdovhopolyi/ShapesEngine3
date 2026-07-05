#pragma once

#include <Common/Singleton.h>
#include <Serialization/Serializable.h>
#include <memory>

namespace shen3
{
    class Serializable;

    class LoaderBase
    {
    public:
        ~LoaderBase() = default;
        virtual std::shared_ptr<Serializable> CreateAndLoad(const DataElementWrapper& serialization) = 0;
    };
}
