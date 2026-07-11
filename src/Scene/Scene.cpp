#include <Scene/Scene.h>

namespace shen3
{
    void Scene::Update()
    {
        for (auto& sceneObject : _sceneObjects) {
            if (sceneObject) {
                sceneObject->Update();
            }
        }
    }
}
