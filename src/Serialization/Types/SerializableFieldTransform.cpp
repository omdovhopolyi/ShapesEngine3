#include <Serialization/Types/SerializableFieldTransform.h>

namespace shen3
{
    SerializableFieldTransform::SerializableFieldTransform(Transform& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    { }

    void SerializableFieldTransform::Load(const DataElementWrapper& element)
    {
        _field = element.GetTransform(_name);
    }
}
