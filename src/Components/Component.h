#pragma once

#include <string>
#include <Serialization/Serializable.h>

namespace shen3
{
    class SceneObject;

    class Component
        : public Serializable
        , public std::enable_shared_from_this<Component>
    {
    public:
        virtual void OnInstantiated() {}
        virtual void OnStarted() {}
        virtual void OnActivated() {}
        virtual void Update(float dt);
        virtual void OnDeactivated() {}
        virtual void OnDestroy() {}

        const std::string& GetName() const;
        void SetName(const std::string& name);

        SceneObject* GetSceneObject() const;
        void SetSceneObject(SceneObject* sceneObject);

    protected:
        std::string _name;
        SceneObject* _sceneObject = nullptr;
    };
}
