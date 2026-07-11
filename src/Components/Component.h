#pragma once

#include <string>

namespace shen3
{
    class SceneObject;

    class Component
    {
    public:
        virtual void OnInstantiate() {}
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
