#include <Serialization/Types/SerializableFieldSetStr.h>

namespace shen3
{
    SerializableFieldSetStr::SerializableFieldSetStr(std::set<std::string>& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    {
    }

    void SerializableFieldSetStr::Load(const DataElementWrapper& element)
    {
        const auto vec = element.GetVecStr(_name);
        _field = { vec.begin(), vec.end() };
    }
}
