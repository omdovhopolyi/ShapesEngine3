#include <Serialization/DataElementWrapperFactory.h>
#include <Serialization/WrapperTypes/XmlDataElementWrapper.h>

namespace shen3
{
    std::shared_ptr<DataElementWrapper> DataElementWrapperFactory::Get()
    {
        return std::make_shared<XmlDataElementWrapper>();
    }

    std::shared_ptr<DataElementWrapper> DataElementWrapperFactory::Get(const std::string& filename)
    {
        auto wrapper = std::make_shared<XmlDataElementWrapper>();
        wrapper->LoadFile(filename);
        return wrapper;
    }
}
