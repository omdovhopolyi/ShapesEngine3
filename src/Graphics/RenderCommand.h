#pragma once

#include <Graphics/Mesh.h>
#include <Graphics/ShaderProgram.h>
#include <Math/Transform.h>

namespace shen3
{
    class RenderCommand
    {
    public:
        void Draw();

    protected:
        Mesh* _mesh = nullptr;
        ShaderProgram* _shader = nullptr;
        Transform _transform;
    };
}