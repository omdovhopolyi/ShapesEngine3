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
        virtual ~ShaderProgram() = default;
        ShaderProgram(const ShaderProgram&) = delete;
        ShaderProgram& operator = (const ShaderProgram&) = delete;

        unsigned int GetProgramId() const;

        virtual int GetUniformLocation(const std::string& name) = 0;

        virtual void SetUniform(const std::string& name, float value) = 0;
        virtual void SetUniform(const std::string& name, const Vec2& value) = 0;
        virtual void SetUniform(const std::string& name, const Mat4& value) = 0;

        virtual void Use() const = 0;

    protected:
        unsigned int _programId = 0;
        std::unordered_map<std::string, int> _uniformLocationCache;
    };
}
