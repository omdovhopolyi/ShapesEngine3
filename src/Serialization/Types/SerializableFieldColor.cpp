#include <Serialization/Types/SerializableFieldColor.h>

namespace shen3
{
    SerializableFieldColor::SerializableFieldColor(Vec4& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    {}

    void SerializableFieldColor::Load(const DataElementWrapper& element)
    {
        _field = element.GetColor(_name);
    }
}
