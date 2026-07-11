#pragma once

#include <Serialization/DataElementWrapper.h>

#include <memory>

namespace shen3
{
    class DataElementWrapperFactory
    {
    public:
        static std::shared_ptr<DataElementWrapper> Get();
        static std::shared_ptr<DataElementWrapper> Get(const std::string& filename);
    };
}
