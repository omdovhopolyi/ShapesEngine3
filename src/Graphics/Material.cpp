#include <Graphics/Material.h>
#include <Graphics/ShaderProgram.h>

namespace shen3
{
    void Material::SetShader(ShaderProgram* shader)
    {
        _shader = shader;
    }

    const ShaderProgram* Material::GetShader() const
    {
        return _shader;
    }

    void Material::SetParam(const std::string& name, float value)
    {
        _floatUniforms[name] = value;
    }

    void Material::SetParam(const std::string& name, const Vec2& value)
    {
        _float2Uniforms[name] = value;
    }

    void Material::SetParam(const std::string& name, const Vec3& value)
    {
        _float3Uniforms[name] = value;
    }

    void Material::SetParam(const std::string& name, const Vec4& value)
    {
        _float4Uniforms[name] = value;
    }

    void Material::SetParam(const std::string& name, const Mat4& value)
    {
        _mat4Uniforms[name] = value;
    }

    void Material::SetTexture(const std::string& type, const unsigned int tex)
    {
        _textures[type] = tex;
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
            for (const auto& [name, value] : _float3Uniforms) {
                _shader->SetUniform(name, value);
            }
            for (const auto& [name, value] : _float4Uniforms) {
                _shader->SetUniform(name, value);
            }
            for (const auto& [name, value] : _mat4Uniforms) {
                _shader->SetUniform(name, value);
            }
            int texIndex = 0;
            for (const auto& [name, value] : _textures) {
                _shader->ActivateTexture(texIndex, value);
                _shader->SetUniform(name, texIndex);
                texIndex++;
            }
        }
    }
}
