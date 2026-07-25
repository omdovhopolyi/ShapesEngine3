#pragma once

#include <Math/Mat.h>

namespace shen3
{
    Mat4 CreateViewMatrix(const Mat4& cameraTransform);
    Mat4 CreateProjectionsMatrix(float fov, float ratio, float near, float far);
}
