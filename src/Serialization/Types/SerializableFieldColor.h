#pragma once

#include <Serialization/SerializableField.h>
#include <Math/Vec4.h>

namespace shen3
{
    class SerializableFieldColor
        : public SerializableField
    {
    public:
        SerializableFieldColor(Vec4& field, const std::string& name);
        void Load(const DataElementWrapper& element) override;

    private:
        Vec4& _field;
    };
}
