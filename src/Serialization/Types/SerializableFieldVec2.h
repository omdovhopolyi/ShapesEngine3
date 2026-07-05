#pragma once

#include <Serialization/SerializableField.h>

namespace shen3
{
    class SerializableFieldVec2
        : public SerializableField
    {
    public:
        SerializableFieldVec2(Vec2& field, const std::string& name);
        void Load(const DataElementWrapper& element) override;

    private:
        Vec2& _field;
    };
}
