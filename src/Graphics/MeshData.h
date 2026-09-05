#pragma once

#include <Math/Math.h>

#include <vector>

#define MAX_BONE_INFLUENCE 4

namespace shen3
{

    struct MeshVertex {
        Vec3 position;
        Vec3 normal;
        Vec2 texCoords;
        Vec3 tangent;
        Vec3 bitangent;
        int boneIDs[MAX_BONE_INFLUENCE];
        float weights[MAX_BONE_INFLUENCE];
    };

    struct MeshData {
        std::vector<MeshVertex> vertices;
        std::vector<unsigned int> indices;
    };
}
