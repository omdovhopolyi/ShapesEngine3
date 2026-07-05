#pragma once

#include <Serialization/Loaders/LoaderBase.h>

namespace shen3
{
    template<class T>
    class LoaderDefault
        : public LoaderBase
    {
    public:
        std::shared_ptr<Serializable> CreateAndLoad(const DataElementWrapper& element) override
        {
            auto serializable = std::make_shared<T>();
            serializable->RegisterProperties();
            serializable->Load(element);
            return serializable;
        }
    };
}
