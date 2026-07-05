#pragma once

#include <Serialization/SerializableField.h>
#include <Math/Transform.h>

namespace shen3
{
    class SerializableFieldTransform
        : public SerializableField
    {
    public:
        SerializableFieldTransform(Transform& field, const std::string& name);
        void Load(const DataElementWrapper& element) override;

    private:
        Transform& _field;
    };
}
