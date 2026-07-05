#include <Serialization/Types/SerializableFieldFloatRect.h>

namespace shen3
{
    SerializableFieldFloatRect::SerializableFieldFloatRect(RectF& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    { }
    
    void SerializableFieldFloatRect::Load(const DataElementWrapper& element)
    {
        _field = element.GetFloatRect(_name);
    }
}
