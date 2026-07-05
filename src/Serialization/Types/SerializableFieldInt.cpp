#include <Serialization/Types/SerializableFieldInt.h>

namespace shen3
{
    SerializableFieldInt::SerializableFieldInt(int& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    { }

    void SerializableFieldInt::Load(const DataElementWrapper& element)
    {
        _field = element.GetInt(_name, _field);
    }
}
