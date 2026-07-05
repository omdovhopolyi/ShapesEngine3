#include <Serialization/Types/SerializableFieldListIntRect.h>

namespace shen3
{
    SerializableFieldListIntRect::SerializableFieldListIntRect(std::vector<RectI>& field, const std::string& name, const std::string& itemId)
        : SerializableField(name)
        , _field(field)
        , _itemId(itemId)
    { }

    void SerializableFieldListIntRect::Load(const DataElementWrapper& element)
    {
        _field = element.GetVectorIntRect(_name, _itemId);
    }
}
