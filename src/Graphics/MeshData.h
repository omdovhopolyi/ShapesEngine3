#pragma once

#include <Math/Math.h>

#include <vector>

namespace shen3
{
    struct Face {
        int a = -1;
        int b = -1;
        int c = -1;
        Vec2 aUV;
        Vec2 bUV;
        Vec2 cUV;
        unsigned int color = 0xFFFFFFFF;
    };

    struct MeshData {
        std::vector<Vec3> vertices;
        std::vector<Vec2> texCoords;
        std::vector<Face> faces;
        std::vector<int> indices;
        std::vector<Vec2> uvs;
    };
}
