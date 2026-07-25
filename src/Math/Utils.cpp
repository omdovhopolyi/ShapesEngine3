#include <Math/Utils.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace shen3
{
    Mat4 CreateViewMatrix(const Mat4& cameraTransform)
    {
        return glm::inverse(cameraTransform);
    }

    Mat4 CreateProjectionsMatrix(float fov, float ratio, float near, float far)
    {
        return glm::perspective(glm::radians(fov), ratio, near, far);
    }
}
