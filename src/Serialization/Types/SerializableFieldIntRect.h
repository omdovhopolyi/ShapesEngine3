#pragma once

#include <Serialization/SerializableField.h>

namespace shen3
{
    class SerializableFieldIntRect
        : public SerializableField
    {
    public:
        SerializableFieldIntRect(RectI& field, const std::string& name);
        void Load(const DataElementWrapper& element) override;

    private:
        RectI& _field;
    };
}
