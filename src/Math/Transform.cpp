#include <Math/Transform.h>
#include <glm/gtc/matrix_transform.hpp>

namespace shen3
{
    void Transform::Translate(const Vec3& offset)
    {
        _position += offset;
        _transform = glm::translate(_transform, offset);
    }

    void Transform::SetPosition(const Vec3& position, bool updateTransform/* = false*/)
    {
        _position = position;
        if (updateTransform) {
            UpdateTransform();
        }
    }

    const Vec3& Transform::GetPosition() const
    {
        return _position;
    }

    void Transform::Rotate(const Vec3& offset)
    {
        _rotation += offset;
        _transform = glm::rotate(_transform, offset.x, { 1.f, 0.f, 0.f });
        _transform = glm::rotate(_transform, offset.y, { 0.f, 1.f, 0.f });
        _transform = glm::rotate(_transform, offset.z, { 0.f, 0.f, 1.f });
    }

    void Transform::SetRotation(const Vec3& rotation, bool updateTransform/* = false*/)
    {
        _rotation = rotation;
        if (updateTransform) {
            UpdateTransform();
        }
    }

    const Vec3& Transform::GetRotation() const
    {
        return _rotation;
    }

    void Transform::Scale(const Vec3& offset)
    {
        _scale += offset;
        _transform = glm::scale(_transform, _scale);
    }

    void Transform::SetScale(const Vec3& scale, bool updateTransform/* = false*/)
    {
        _scale = scale;
        if (updateTransform) {
            UpdateTransform();
        }
    }

    const Vec3& Transform::GetScale() const
    {
        return _scale;
    }

    const Mat4& Transform::GetLocalTransform() const
    {
        return _transform;
    }

    Mat4 Transform::GetWorldTransform(const Mat4& parentTransform)
    {
        return parentTransform * _transform;
    }

    void Transform::UpdateTransform()
    {
        _transform = Mat4(1.f);
        _transform = glm::translate(_transform, _position);
        _transform = glm::rotate(_transform, _rotation.x, { 1.f, 0.f, 0.f });
        _transform = glm::rotate(_transform, _rotation.y, { 0.f, 1.f, 0.f });
        _transform = glm::rotate(_transform, _rotation.z, { 0.f, 0.f, 1.f });
        _transform = glm::scale(_transform, _scale);
    }
}
