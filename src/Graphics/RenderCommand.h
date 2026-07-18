#pragma once

#include <Graphics/Mesh.h>
#include <Graphics/Material.h>
#include <Math/Transform.h>

namespace shen3
{
    struct RenderCommand
    {
    public:
        //void Draw();

    //protected:
        Mesh* mesh = nullptr;
        Material* material = nullptr;
        Transform transform;
    };
}