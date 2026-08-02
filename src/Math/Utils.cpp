#include <Math/Utils.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace shen3
{
    Mat4 CreateViewMatrix(const Transform& transform)
    {
        const auto position = transform.GetPosition();
        const auto forward = transform.GetForward();
        const auto right = transform.GetRight();
        const auto up = Normalize(glm::cross(right, forward));

        return glm::lookAt(position, position + forward, up);
    }

    Mat4 CreateProjectionsMatrix(float fov, float ratio, float near, float far)
    {
        return glm::perspective(glm::radians(fov), ratio, near, far);
    }

    Vec2 Normalize(const Vec2& vec)
    {
        return glm::normalize(vec);
    }

    void NormalizeThis(Vec2& vec)
    {
        vec = glm::normalize(vec);
    }

    Vec3 Normalize(const Vec3& vec)
    {
        return glm::normalize(vec);
    }

    void NormalizeThis(Vec3& vec)
    {
        vec = glm::normalize(vec);
    }
}
