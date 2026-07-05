#include <Serialization/Types/SerializableFieldFloat.h>

namespace shen3
{
    SerializableFieldFloat::SerializableFieldFloat(float& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    {}

    void SerializableFieldFloat::Load(const DataElementWrapper& element)
    {
        _field = element.GetFloat(_name, _field);
    }
}
