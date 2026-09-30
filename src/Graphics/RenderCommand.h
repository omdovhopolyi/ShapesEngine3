#pragma once

#include <Math/Transform.h>

namespace shen3
{
    class Mesh;
    class Material;
    class RenderTarget;

    struct RenderCommand
    {
        Mesh* mesh = nullptr;
        Material* material = nullptr;
        Mat4 transform;
        Mat4 transposeInvMat;
        RenderTarget* renderTarget = nullptr;
    };
}