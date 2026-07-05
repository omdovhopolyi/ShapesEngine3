#include <Serialization/SerializableField.h>

namespace shen3
{
    SerializableField::SerializableField(const std::string& name)
        : _name(name)
    {}

    SerializableField::~SerializableField() = default;
}
