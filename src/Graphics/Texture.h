#pragma once

namespace shen3
{
    class Texture
    {
    public:
        Texture(unsigned int id, unsigned int width, unsigned int height, unsigned int numChannels);

        unsigned int GetId() const;
        unsigned int GetWidth() const;
        unsigned int GetHeight() const;
        unsigned int GetNumChannels() const;

    private:
        unsigned int _texId = 0;
        unsigned int _width = 0;
        unsigned int _height = 0;
        unsigned int _numChannels = 0;
    };
}
