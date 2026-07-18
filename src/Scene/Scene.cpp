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

    void Scene::AddSceneObject(std::unique_ptr<SceneObject> sceneObject)
    {
        _sceneObjects.push_back(std::move(sceneObject));
    }

    SceneObject* Scene::CreateSceneObject(SceneObject* parent, const std::string& name/* = "node"*/)
    {
        auto sceneObjectPtr = std::make_unique<SceneObject>(name);
        auto sceneObject = sceneObjectPtr.get();
        sceneObject->SetScene(this);
        if (parent) {
            sceneObject->SetParent(parent);
        }
        else {
            _sceneObjects.push_back(std::move(sceneObjectPtr));
        }
        
        return sceneObject;
    }

    void Scene::RemoveSceneObject()
    {
        for (auto& sceneObject : _toDestroy) {
            if (auto sharedSceneObject = sceneObject.lock()) {
                auto parent = sharedSceneObject->GetParent();
                if (parent) {
                    parent->RemoveChild(sharedSceneObject.get());
                }
            }
        }
    }
}
