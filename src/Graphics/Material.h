#pragma once

#include <Math/Vec.h>
#include <Math/Mat.h>

#include <map>
#include <string>

namespace shen3
{
    class ShaderProgram;

    class Material
    {
    public:
        void SetShader(ShaderProgram* shader);
        const ShaderProgram* GetShader() const;

        void SetParam(const std::string& name, float value);
        void SetParam(const std::string& name, const Vec2& value);
        void SetParam(const std::string& name, const Vec3& value);
        void SetParam(const std::string& name, const Vec4& value);
        void SetParam(const std::string& name, const Mat4& value);

        void Use();

    private:
        ShaderProgram* _shader = nullptr;

        std::unordered_map<std::string, float> _floatUniforms;
        std::unordered_map<std::string, Vec2> _float2Uniforms;
        std::unordered_map<std::string, Vec3> _float3Uniforms;
        std::unordered_map<std::string, Vec4> _float4Uniforms;
        std::unordered_map<std::string, Mat4> _mat4Uniforms;
    };
}
