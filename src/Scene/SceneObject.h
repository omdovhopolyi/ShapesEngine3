#pragma once

#include <Math/Transform.h>
#include <Components/Component.h>
#include <Enums/SceneObjectStatesEnum.h>

#include <vector>
#include <memory>
#include <string>
#include <map>
#include <typeinfo>
#include <typeindex>

namespace shen3
{
    class SceneObject
    {
    public:
        SceneObject();
        virtual ~SceneObject();
        SceneObject(const std::string& name);
        SceneObject(const SceneObject& other) = delete;
        SceneObject(SceneObject&& other) = delete;
        SceneObject& operator = (const SceneObject& other) = delete;
        SceneObject& operator = (SceneObject&& other) = delete;

        void Update(float dt);

        const std::string& GetName() const;
        void SetName(const std::string& name);

        const Transform& GetTransform() const;
        void SetTransform(const Transform& transform);

        SceneObject* GetParent() const;
        void SetParent(SceneObject* parent);

        void CreateChild(const std::string& name = "node");
        void AddChild(std::unique_ptr<SceneObject> node);
        SceneObject* GetChild(const std::string& name) const;
        SceneObject* GetChild(int index) const;
        std::unique_ptr<SceneObject> ReleaseChild(const SceneObject* sceneObject);
        void RemoveChild(const SceneObject* sceneObject);

        SceneObjectState GetState() const;
        void SetState(SceneObjectState state);

        bool IsActive() const;
        void SetActive(bool active);

        bool IsVisible() const;
        void SetVisible(bool visible);

        template<class T>
        T* GetComponentByType() const;

        template<class T>
        T* GetComponentByType(const std::string& name) const;

        template<class T>
        T* GetOrCreateComponentByType();

        template<class T>
        T* AddComponent();

        template<class T>
        T* AddComponent(const std::string& name);

        template<class T>
        bool HasComponent() const;

        Component* GetComponent(const std::string& name) const;
        bool HasComponent(const std::string& name) const;

    private:
        bool IsChild(const SceneObject* sceneObject);

    private:
        std::string _name;
        SceneObjectState _state = SceneObjectState::Undefined;
        bool _isActive = true;
        bool _isVisible = true;
        Transform _transform;
        SceneObject* _parent = nullptr;
        std::vector<std::unique_ptr<SceneObject>> _children;
        std::vector<std::unique_ptr<Component>> _components;
        std::map<std::type_index, Component*> _mappedComponents;
    };

    template<class T>
    T* SceneObject::GetComponentByType() const
    {
        auto index = std::type_index(typeid(T));
        if (auto it = _mappedComponents.find(index); it != _mappedComponents.end()) {
            it->second;
        }
        return nullptr;
    }

    template<class T>
    T* SceneObject::GetComponentByType(const std::string& name) const
    {
        auto [begin, end] = _mappedComponents.equal_range(std::type_index(typeid(T)));
        auto foundIt = std::find_if(begin, end, [&name](const auto& it) {
            return it->second->GetName() == name;
        });
        if (foundIt != _mappedComponents.end()) {
            foundIt->second;
        }
        return nullptr;
    }

    template<class T>
    T* SceneObject::GetOrCreateComponentByType()
    {
        auto comp = GetComponentByType<T>();
        if (comp == nullptr) {
            comp = AddComponent<T>();
        }
        return comp;
    }

    template<class T>
    T* SceneObject::AddComponent()
    {
        auto compPtr = std::make_unique<T>();
        compPtr->SetSceneObject(this);
        auto comp = compPtr.get();
        _components.push_back(std::move(compPtr));
        _mappedComponents[std::type_index(typeid(T))] = comp;
        return comp;
    }

    template<class T>
    T* SceneObject::AddComponent(const std::string& name)
    {
        auto compPtr = std::make_unique<T>();
        compPtr->SetName(name);
        compPtr->SetSceneObject(this);
        auto comp = compPtr.get();
        _components.push_back(std::move(compPtr));
        _mappedComponents[std::type_index(typeid(T))] = comp;
        return comp;
    }

    template<class T>
    bool SceneObject::HasComponent() const
    {
        auto index = std::type_index(typeid(T));
        auto it = _mappedComponents.find(index);
        return it != _mappedComponents.end();
    }
}
