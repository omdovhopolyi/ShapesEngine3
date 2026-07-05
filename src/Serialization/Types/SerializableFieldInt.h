#pragma once

#include <Serialization/SerializableField.h>

namespace shen3
{
    class SerializableFieldInt
        : public SerializableField
    {
    public:
        SerializableFieldInt(int& field, const std::string& name);
        void Load(const DataElementWrapper& element) override;

    private:
        int& _field;
    };
}
