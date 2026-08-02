#include <Math/Transform.h>
#include <Math/Vec4.h>
#include <Math/Utils.h>
#include <glm/gtc/matrix_transform.hpp>

namespace shen3
{
    void Transform::Translate(const Vec3& offset)
    {
        _position += offset;
        SetDirty(true);
    }

    void Transform::SetPosition(const Vec3& position)
    {
        _position = position;
        SetDirty(true);
    }

    const Vec3& Transform::GetPosition() const
    {
        return _position;
    }

    void Transform::Rotate(const Quat& rotation)
    {
        _rotation = rotation * _rotation;
        SetDirty(true);
    }

    void Transform::Rotate(Vec3 angles)
    {
        angles.x = glm::radians(angles.x);
        angles.y = glm::radians(angles.y);
        angles.z = glm::radians(angles.z);
        _rotation = Quat(angles) * _rotation;
        SetDirty(true);
    }

    void Transform::Rotate(float angle, const Vec3& axis)
    {
        Quat rot = glm::angleAxis(glm::radians(angle), axis);
        _rotation = rot * _rotation;
        SetDirty(true);
    }

    void Transform::SetRotation(float angle, const Vec3& axis)
    {
        _rotation = glm::angleAxis(glm::radians(angle), axis);
        SetDirty(true);
    }

    void Transform::SetRotation(const Vec3& angles)
    {
        _rotation = Quat{ angles };
        SetDirty(true);
    }

    void Transform::SetRotation(const Quat& rotation)
    {
        _rotation = rotation;
        SetDirty(true);
    }

    const Quat& Transform::GetRotation() const
    {
        return _rotation;
    }

    void Transform::Scale(const Vec3& offset)
    {
        _scale += offset;
        SetDirty(true);
    }

    void Transform::SetScale(const Vec3& scale)
    {
        _scale = scale;
        SetDirty(true);
    }

    const Vec3& Transform::GetScale() const
    {
        return _scale;
    }

    Vec3 Transform::GetForward() const
    {
        return _rotation * Vec3(0.f, 0.f, -1.f);
    }

    Vec3 Transform::GetRight() const
    {
        return _rotation * Vec3(1.f, 0.f, 0.f);
    }

    Mat4 Transform::GetLocalTransformMat() const
    {
        return _transform;
    }

    Mat4 Transform::GetWorldTransformMat(const Mat4& parentTransform) const
    {
        return parentTransform * GetLocalTransformMat();
    }

    void Transform::UpdateTransform()
    {
        if (IsDirty()) {
            SetDirty(false);

            _transform = Mat4(1.f);
            _transform = glm::translate(_transform, _position);
            _transform = _transform * glm::mat4_cast(_rotation);
            //_transform = glm::rotate(_transform, glm::radians(_rotation.y), { 0.f, 1.f, 0.f });
            //_transform = glm::rotate(_transform, glm::radians(_rotation.x), { 1.f, 0.f, 0.f });
            //_transform = glm::rotate(_transform, glm::radians(_rotation.z), { 0.f, 0.f, 1.f });
            _transform = glm::scale(_transform, _scale);
        }
    }

    void Transform::SetDirty(bool dirty)
    {
        _isDirty = dirty;
    }

    bool Transform::IsDirty() const
    {
        return _isDirty;
    }
}
