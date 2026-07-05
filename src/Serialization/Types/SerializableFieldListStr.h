#pragma once

#include <Serialization/SerializableField.h>
#include <vector>

namespace shen3
{
    class SerializableFieldListStr
        : public SerializableField
    {
    public:
        SerializableFieldListStr(std::vector<std::string>& field, const std::string& name);
        void Load(const DataElementWrapper& element) override;

    private:
        std::vector<std::string>& _field;
    };
}
