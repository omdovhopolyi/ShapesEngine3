#pragma once

#include <Serialization/SerializableField.h>
#include <Math/Rect.h>

namespace shen3
{
    class SerializableFieldFloatRect
        : public SerializableField
    {
    public:
        SerializableFieldFloatRect(RectF& field, const std::string& name);
        void Load(const DataElementWrapper& element) override;

    private:
        RectF& _field;
    };
}
