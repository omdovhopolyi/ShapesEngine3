#include <Serialization/Types/SerializableFieldVec2.h>

namespace shen3
{
    SerializableFieldVec2::SerializableFieldVec2(Vec2& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    { }

    void SerializableFieldVec2::Load(const DataElementWrapper& element)
    {
        _field = element.GetVec2(_name, _field);
    }
}
