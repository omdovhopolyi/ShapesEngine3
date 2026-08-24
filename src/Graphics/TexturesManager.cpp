#include <Graphics/TexturesManager.h>
#include <Serialization/DataElementWrapperFactory.h>
#include <Common/FilePath.h>
#include <Managers/ManagersController.h>
#include <Logger/Logger.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glad/gl.h>

namespace shen3
{
    REGISTER_MANAGERS_FACTORY(TexturesManager)

    void TexturesManager::Load()
    {
        auto elementWrapper = DataElementWrapperFactory::Get(FilePath::Path("assets/configs/textures.xml"));
        elementWrapper->ForAllChildren("texture", [&](const DataElementWrapper& element) {
            const auto id = element.GetStr("id");
            const auto filename = element.GetStr("file");
            LoadTexture(id, filename);
        });
    }

    Texture* TexturesManager::GetTexture(const std::string& id) const
    {
        auto it = _textures.find(id);
        return (it != _textures.end()) ? it->second.get() : nullptr;
    }

    void TexturesManager::AddTexture(const std::string& id, std::unique_ptr<Texture> texture)
    {
        _textures[id] = std::move(texture);
    }

    void TexturesManager::LoadTexture(const std::string& id, const std::string& filename)
    {
        const auto path = FilePath::Path(filename);

        int width = 0;
        int height = 0;
        int numChannels = 0;

        unsigned char* texData = stbi_load(path.c_str(), &width, &height, &numChannels, STBI_rgb_alpha);
        
        unsigned int texId = 0;

        glGenTextures(1, &texId);
        glBindTexture(GL_TEXTURE_2D, texId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);

        const auto error = glGetError();
        if (error != GL_NO_ERROR) {
            Logger::Err("[TexturesManager::LoadTexture] Error {} while loading texture {}", error, filename);
            return;
        }

        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        stbi_image_free(texData);

        _textures[id] = std::make_unique<Texture>(texId, width, height, numChannels);
    }
}