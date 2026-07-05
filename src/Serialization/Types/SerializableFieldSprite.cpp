#include <Serialization/Types/SerializableFieldSprite.h>

namespace shen3
{
    /*SerializableFieldSprite::SerializableFieldSprite(sf::Sprite& field, const std::string& name)
        : SerializableField(name)
        , _field(field)
    { }

    void SerializableFieldSprite::Load(const DataElementWrapper& element)
    {
        if (auto systems = element.GetSystems())
        {
            if (const auto spritesCollection = systems->GetSystem<SfmlSpritesCollection>())
            {
                const auto spriteId = element.GetStr(_name);
                _field = spritesCollection->GetSprite(spriteId);
            }
        }
    }*/
}
