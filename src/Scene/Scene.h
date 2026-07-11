#pragma once

#include <Scene/SceneObject.h>

#include <vector>
#include <memory>

namespace shen3
{
    class Scene
    {
    public:
        void Update();

    private:
        std::vector<std::shared_ptr<SceneObject>> _sceneObjects;
    };
}
