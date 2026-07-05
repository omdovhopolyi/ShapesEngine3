#include <Serialization/Types/SerializableFieldString.h>

namespace shen3
{
    SerializableFieldString::SerializableFieldString(std::string& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    { }

    void SerializableFieldString::Load(const DataElementWrapper& element)
    {
        _field = element.GetStr(_name);
    }
}
