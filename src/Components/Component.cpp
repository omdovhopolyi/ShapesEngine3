#include <Components/Component.h>

namespace shen3
{
    void Component::Update(float)
    {

    }

    const std::string& Component::GetName() const
    {
        return _name;
    }

    void Component::SetName(const std::string& name)
    {
        _name = name;
    }

    SceneObject* Component::GetSceneObject() const
    {
        return _sceneObject;
    }

    void Component::SetSceneObject(SceneObject* sceneObject)
    {
        _sceneObject = sceneObject;
    }
}
