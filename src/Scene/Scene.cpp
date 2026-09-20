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

    void Scene::AddSceneObject(const std::shared_ptr<SceneObject>& sceneObject)
    {
        _sceneObjects.push_back(sceneObject);
    }

    SceneObject* Scene::CreateSceneObject(SceneObject* parent, const std::string& name/* = "node"*/)
    {
        auto sceneObjectPtr = std::make_shared<SceneObject>(name);
        //auto sceneObject = sceneObjectPtr.get();
        sceneObjectPtr->SetScene(this);
        if (parent) {
            sceneObjectPtr->SetParent(parent);
        }
        else {
            _sceneObjects.push_back(sceneObjectPtr);
        }
        sceneObjectPtr->SetState(SceneObjectState::Instantiated);
        return sceneObjectPtr.get();
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
