#include <Scene/Scene.h>

namespace shen3
{
    void Scene::Update(float dt)
    {
        for (auto& sceneObject : _sceneObjects) {
            if (sceneObject) {
                sceneObject->Update(dt);
            }
        }
    }
}
