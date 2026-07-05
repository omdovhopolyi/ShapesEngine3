#include <Serialization/Types/SerializableFieldIntRect.h>

namespace shen3
{
    SerializableFieldIntRect::SerializableFieldIntRect(RectI& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    { }

    void SerializableFieldIntRect::Load(const DataElementWrapper& element)
    {
        _field = element.GetIntRect(_name, _field);
    }
}
