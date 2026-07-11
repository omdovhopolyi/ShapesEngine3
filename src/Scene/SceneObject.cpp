#include <Scene/SceneObject.h>

namespace shen3
{
    void SceneObject::Update()
    {
        for (auto& child : _children) {
            if (child) {
                child->Update();
            }
        }
    }
}
