#include <Serialization/Types/SerializableFieldListStr.h>

namespace shen3
{
    SerializableFieldListStr::SerializableFieldListStr(std::vector<std::string>& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    { }

    void SerializableFieldListStr::Load(const DataElementWrapper& element)
    {
        _field = element.GetVecStr(_name);
    }
}
