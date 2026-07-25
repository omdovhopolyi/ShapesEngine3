#include <Scene/SceneObject.h>
#include <Common/Assert.h>

#include <algorithm>

namespace shen3
{
    SceneObject::SceneObject() = default;

    SceneObject::~SceneObject() = default;

    SceneObject::SceneObject(const std::string& name)
        : _name(name)
    { }

    void SceneObject::Update(float dt)
    {
        if (GetState() == SceneObjectState::Instantiated) {
            for (auto& component : _components) {
                component->OnStarted();
            }

            SetState(SceneObjectState::Alive);
        }

        if (IsActive() && GetState() == SceneObjectState::Alive) {
            for (auto& component : _components) {
                component->Update(dt);
            }
        }

        for (auto& child : _children) {
            if (child) {
                child->Update(dt);
            }
        }
    }

    const std::string& SceneObject::GetName() const
    {
        return _name;
    }

    void SceneObject::SetName(const std::string& name)
    {
        _name = name;
    }

    const Transform& SceneObject::GetLocalTransform() const
    {
        return _transform;
    }

    void SceneObject::SetLocalTransform(const Transform& transform)
    {
        _transform = transform;
    }

    Mat4 SceneObject::GetWorldTransformMat() const
    {
        if (_parent) {
            return _transform.GetWorldTransformMat(_parent->GetLocalTransform().GetLocalTransformMat());
        }
        return _transform.GetLocalTransformMat();
    }

    SceneObject* SceneObject::GetParent() const
    {
        return _parent;
    }

    void SceneObject::SetParent(SceneObject* parent)
    {
        if (parent == this) {
            Assert(false, "[SceneObject::SetParent] parent == this");
            return;
        }
        const bool isChild = IsChild(parent);
        if (isChild) {
            Assert(false, "[SceneObject::SetParent] trying move object to its child");
            return;
        }
        if (_parent == parent) {
            return;
        }

        if (_parent) {
            auto thisPtr = _parent->ReleaseChild(this);
            _parent = parent;
            _parent->AddChild(std::move(thisPtr));
        }
        else {
            _parent = parent;
            auto thisPtr = std::make_shared<SceneObject>(_name);
            thisPtr.reset(this);
            _parent->AddChild(std::move(thisPtr));
        }
    }

    void SceneObject::CreateChild(const std::string& name/* = "node"*/)
    {
        _children.push_back(std::make_shared<SceneObject>(name));
    }

    void SceneObject::AddChild(std::shared_ptr<SceneObject> node)
    {
        _children.push_back(std::move(node));
    }

    SceneObject* SceneObject::GetChild(const std::string& name) const
    {
        auto it = std::find_if(_children.begin(), _children.end(), [&name](const auto& child) {
            return child->GetName() == name;
        });
        if (it != _children.end()) {
            return it->get();
        }
        return nullptr;
    }

    SceneObject* SceneObject::GetChild(int index) const
    {
        if (index < 0 || index >= static_cast<int>(_children.size())) {
            return nullptr;
        }
        return _children[index].get();
    }

    std::shared_ptr<SceneObject> SceneObject::ReleaseChild(const SceneObject* sceneObject)
    {
        auto it = std::find_if(_children.begin(), _children.end(), [sceneObject](const auto& child) {
            return child.get() == sceneObject;
        });
        if (it != _children.end()) {
            auto object = std::move(*it);
            _children.erase(it);
            return object;
        }
        return nullptr;
    }

    void SceneObject::RemoveChild(const SceneObject* sceneObject)
    {
        _children.erase(std::remove_if(_children.begin(), _children.end(), [sceneObject](const auto& child) {
            return child.get() == sceneObject;
        }));
    }

    SceneObjectState SceneObject::GetState() const
    {
        return _state;
    }

    void SceneObject::SetState(SceneObjectState state)
    {
        _state = state;
    }

    void SceneObject::SetScene(Scene* scene)
    {
        _scene = scene;
    }

    Scene* SceneObject::GetScene() const
    {
        return _scene;
    }

    bool SceneObject::IsActive() const
    {
        return _isActive;
    }

    void SceneObject::SetActive(bool active)
    {
        _isActive = active;
    }

    bool SceneObject::IsVisible() const
    {
        return _isVisible;
    }

    void SceneObject::SetVisible(bool visible)
    {
        _isVisible = visible;
    }

    Component* SceneObject::GetComponent(const std::string& name) const
    {
        auto it = std::find_if(_components.begin(), _components.end(), [&name](const auto& comp) {
            return comp->GetName() == name;
        });
        if (it != _components.end()) {
            return it->get();
        }
        return nullptr;
    }

    bool SceneObject::HasComponent(const std::string& name) const
    {
        auto comp = GetComponent(name);
        return comp != nullptr;
    }

    bool SceneObject::IsChild(const SceneObject* sceneObject)
    {
        bool isChild = false;
        for (const auto& child : _children) {
            if (child && child.get() == sceneObject) {
                return true;
            }
            isChild = child->IsChild(sceneObject);
        }
        return isChild;
    }
}
