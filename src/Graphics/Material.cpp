#include <Graphics/Material.h>
#include <Graphics/ShaderProgram.h>

namespace shen3
{
    void Material::SetShader(ShaderProgram* shader)
    {
        _shader = shader;
    }

    void Material::SetParam(const std::string& name, float value)
    {
        _floatUniforms[name] = value;
    }

    void Material::SetParam(const std::string& name, const Vec2& value)
    {
        _float2Uniforms[name] = value;
    }

    void Material::SetParam(const std::string& name, const Mat4& value)
    {
        _mat4Uniforms[name] = value;
    }

    void Material::Use()
    {
        if (_shader) {
            _shader->Use();

            for (const auto& [name, value] : _floatUniforms) {
                _shader->SetUniform(name, value);
            }
            for (const auto& [name, value] : _float2Uniforms) {
                _shader->SetUniform(name, value);
            }
            for (const auto& [name, value] : _mat4Uniforms) {
                _shader->SetUniform(name, value);
            }
        }
    }
}
