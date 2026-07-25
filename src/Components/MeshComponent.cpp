#include <Components/MeshComponent.h>
#include <Graphics/Mesh.h>
#include <Graphics/Material.h>
#include <Graphics/RenderQueue.h>
#include <Math/Transform.h>
#include <Scene/Scene.h>
#include <Managers/ManagersFacade.h>

namespace shen3
{
    REGISTER_LOADER(MeshComponent);

    void MeshComponent::Update(float)
    {
        if (_mesh && _material) {
            const auto transform = _sceneObject->GetWorldTransformMat();
            auto renderQueue = ManagersFacade::Instance().GetManager<RenderQueue>();

            RenderCommand command;
            command.mesh = _mesh;
            command.material = _material;
            command.transform = transform;
            renderQueue->AddCommand(std::move(command));
        }
    }

    void MeshComponent::SetMesh(Mesh* mesh)
    { 
        _mesh = mesh; 
    }

    void MeshComponent::SetMaterial(Material* material)
    {
        _material = material;
    }
}
