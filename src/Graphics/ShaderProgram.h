#pragma once

#include <Math/Math.h>

#include <string>
#include <map>

namespace shen3
{
    class ShaderProgram
    {
    public:
        ShaderProgram(unsigned int id);
        ShaderProgram(const ShaderProgram&) = delete;
        ShaderProgram& operator = (const ShaderProgram&) = delete;

        unsigned int GetProgramId() const;

        void SetUniform(const std::string& name, float value);
        void SetUniform(const std::string& name, const Vec2& value);
        void SetUniform(const std::string& name, const Mat4& value);

        void Use() const;

    private:
        unsigned int _programId = 0;
        std::unordered_map<std::string, int> m_uniformLocationCache;
    };
}
