#pragma once

#include <Graphics/ShaderProgram.h>

namespace shen3
{
    class OpenGLShaderProgram final
        : public ShaderProgram
    {
    public:
        OpenGLShaderProgram(unsigned int id);

        int GetUniformLocation(const std::string& name) override;

        void SetUniform(const std::string& name, float value) override;
        void SetUniform(const std::string& name, const Vec2& value) override;
        void SetUniform(const std::string& name, const Mat4& value) override;

        void Use() const override;
    };
}