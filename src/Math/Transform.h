#pragma once

#include <Math/Vec3.h>
#include <Math/Mat4.h>
#include <Math/Quat.h>

namespace shen
{
    class Transform
    {
    public:
        void Move(const Vec3& offset);
        void SetPosition(const Vec3& position, bool updateTransform = false);
        const Vec3& GetPosition() const;

        void Rotate(const Vec3& offset);
        void SetRotation(const Vec3& rotation, bool updateTransform = false);
        const Vec3& GetRotation() const;

        void Scale(const Vec3& offset);
        void SetScale(const Vec3& scale, bool updateTransform = false);
        const Vec3& GetScale() const;

        const Mat4& GetLocalTransform() const;
        Mat4 GetWorldTransform(const Mat4& parentTransform);

        void UpdateTransform();

    private:
        Vec3 _position = Vec3(0.f);
        Vec3 _rotation = Vec3(0.f);
        Vec3 _scale = Vec3(1.f);
        Mat4 _transform = Mat4(1.f);
        Quat _quat;
    };
}
