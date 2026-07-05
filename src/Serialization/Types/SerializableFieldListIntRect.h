#pragma once

#include <Serialization/SerializableField.h>
#include <vector>

namespace shen3
{
    class SerializableFieldListIntRect
        : public SerializableField
    {
    public:
        SerializableFieldListIntRect(std::vector<RectI>& field, const std::string& name, const std::string& itemId = "item");
        void Load(const DataElementWrapper& element) override;

    private:
        std::vector<RectI>& _field;
        std::string _itemId;
    };
}
