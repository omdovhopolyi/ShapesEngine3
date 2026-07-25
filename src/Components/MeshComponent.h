#pragma once

#include <Components/Component.h>

namespace shen3
{
    class Mesh;
    class Material;

    class MeshComponent
        : public Component
    {
        SERIALIZABLE(MeshComponent)

    public:
        void Update(float dt) override;

        void SetMesh(Mesh* mesh);
        void SetMaterial(Material* material);

    private:
        Mesh* _mesh = nullptr;
        Material* _material = nullptr;
    };
}
