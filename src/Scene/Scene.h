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

        /*void AddSceneObject(const std::shared_ptr<SceneObject>& sceneObject);
        void RemoveSceneObject();*/

    private:
        std::vector<std::unique_ptr<SceneObject>> _sceneObjects;
    };
}
