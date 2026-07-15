#pragma once

#include <Math/Vec2.h>
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
        void SetParam(const std::string& name, float value);
        void SetParam(const std::string& name, const Vec2& value);
        void SetParam(const std::string& name, const Mat4& value);

        void Use();

    private:
        ShaderProgram* _shader = nullptr;
        std::unordered_map<std::string, float> _floatUniforms;
        std::unordered_map<std::string, Vec2> _float2Uniforms;
        std::unordered_map<std::string, Mat4> _mat4Uniforms;
    };
}
