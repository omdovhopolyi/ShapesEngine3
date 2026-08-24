#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Graphics/Texture.h>

namespace shen3
{
    class DataElementWrapper;

    class TexturesManager
        : public Manager
    {
        MANAGERS_FACTORY(TexturesManager)

    public:
        void Load() override;

        Texture* GetTexture(const std::string& id) const;
        void AddTexture(const std::string& id, std::unique_ptr<Texture> texture);

    protected:
        void LoadTexture(const std::string& id, const std::string& filename);

    protected:
        std::unordered_map<std::string, std::unique_ptr<Texture>> _textures;
    };
}