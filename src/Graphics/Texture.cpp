#include <Graphics/Texture.h>

namespace shen3
{
    Texture::Texture(unsigned int id, unsigned int width, unsigned int height, unsigned int numChannels)
        : _texId(id)
        , _width(width)
        , _height(height)
        , _numChannels(numChannels)
    {}

    unsigned int Texture::GetId() const
    {
        return _texId;
    }

    unsigned int Texture::GetWidth() const
    {
        return _width;
    }

    unsigned int Texture::GetHeight() const
    {
        return _height;
    }

    unsigned int Texture::GetNumChannels() const
    {
        return _numChannels;
    }
}
