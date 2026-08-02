#pragma once

#include <Math/Math.h>

namespace shen3
{
    Mat4 CreateViewMatrix(const Transform& transform);
    Mat4 CreateProjectionsMatrix(float fov, float ratio, float near, float far);
    Vec2 Normalize(const Vec2& vec);
    void NormalizeThis(Vec2& vec);
    Vec3 Normalize(const Vec3& vec);
    void NormalizeThis(Vec3& vec);
}
