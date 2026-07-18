#pragma once

#include <Scene/SceneObject.h>

#include <vector>
#include <memory>

namespace shen3
{
    class Scene
    {
    public:
        void Update(float dt);

        void AddSceneObject(std::unique_ptr<SceneObject> sceneObject);
        void RemoveSceneObject();

        SceneObject* CreateSceneObject(SceneObject* parent, const std::string& name = "node");

    private:
        void DestroySceneObjects();

    private:
        std::vector<std::unique_ptr<SceneObject>> _sceneObjects;
        std::vector<std::weak_ptr<SceneObject>> _toDestroy;
    };
}
