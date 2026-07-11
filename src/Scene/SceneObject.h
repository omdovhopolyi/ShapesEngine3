#pragma once

#include <Math/Transform.h>

#include <vector>
#include <memory>

namespace shen3
{
    class SceneObject
    {
    public:
        void Update();

    private:
        Transform _transrom;
        SceneObject* _parent = nullptr;
        std::vector<std::shared_ptr<SceneObject>> _children;
    };
}
