#pragma once

#include <Math/Vec3.h>
#include <Math/Mat4.h>
#include <Math/Quat.h>

namespace shen3
{
    class Transform
    {
    public:
        void Update();

        void Translate(const Vec3& offset);
        void SetPosition(const Vec3& position);
        const Vec3& GetPosition() const;

        void Rotate(const Vec3& offset);
        void SetRotation(const Vec3& rotation);
        const Vec3& GetRotation() const;

        void Scale(const Vec3& offset);
        void SetScale(const Vec3& scale);
        const Vec3& GetScale() const;

        Vec3 GetForward() const;
        Vec3 GetRight() const;

        Mat4 GetLocalTransformMat() const;
        Mat4 GetWorldTransformMat(const Mat4& parentTransform) const;

        void UpdateTransform();

        void SetDirty(bool dirty);
        bool IsDirty() const;

    private:
        Vec3 _position = Vec3(0.f);
        Vec3 _rotation = Vec3(0.f);
        Vec3 _scale = Vec3(1.f);
        Mat4 _transform = Mat4(1.f);
        Quat _quat;
        bool _isDirty = true;
    };
}
