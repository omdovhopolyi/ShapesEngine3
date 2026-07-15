#pragma once

#include <Managers/BaseManagers/Manager.h>
#include <Managers/BaseManagers/RenderManager.h>
#include <Managers/BaseManagers/UpdateManager.h>
#include <Messenger/SubscriptionsContainer.h>
#include <Logger/Logger.h>

#include <memory>
#include <vector>
#include <map>
#include <typeinfo>
#include <typeindex>
#include <format>

namespace shen3
{
    class Engine;
    class TimeManager;
    class PlayerWindowInputManager;

    class ManagersController
    {
    public:
        void Init(Engine* engine);

        template<class T, class... Args>
        void RegisterManager(Args... args);

        template <class T>
        T* GetManager() const;

        void AddManager(std::unique_ptr<Manager>&& manager);

        void Load();
        void Start();
        void Update();
        void Draw();
        void Save();
        void Stop();
        void Clear();

        float GetDt() const;
        float GetGameDt() const;
        TimeManager& GetTime() { return *_timeManager; }
        const PlayerWindowInputManager* GetInput() { return _playerInputManager; }

    private:
        void InitSubscriptions();
        void OnLostFocus();
        void OnGainedFocus();

    private:
        std::vector<std::unique_ptr<Manager>> _simpleManagers;
        std::vector<std::unique_ptr<UpdateManager>> _updateManagers;
        std::vector<std::unique_ptr<RenderManager>> _renderManagers;
        std::map<std::type_index, Manager*> _mappedManagers;
        std::vector<Manager*> _registrationOrderedManagers;
        TimeManager* _timeManager = nullptr;
        PlayerWindowInputManager* _playerInputManager = nullptr;
        Engine* _engine = nullptr;

        SubcriptionsContainer _subscriptions;
    };

    template <class T, class... Args>
    void ManagersController::RegisterManager(Args... args)
    {
        auto manager = std::make_unique<T>(std::forward<Args>(args)...);
        manager->Init(this);
        _mappedManagers[std::type_index(typeid(T))] = manager.get();
        _registrationOrderedManagers.push_back(manager.get());

        /*if constexpr (std::is_base_of_v<TimeManager, T>) {
            _timeSystem = system.get();
        }*/

        if constexpr (std::is_base_of_v<RenderManager, T>) {
            _renderManagers.push_back(std::move(manager));
            Logger::Log(std::format("Register {} render manager", typeid(T).name()));
        }
        else if constexpr (std::is_base_of_v<UpdateManager, T>) {
            _updateManagers.push_back(std::move(manager));
            Logger::Log(std::format("Register {} update manager", typeid(T).name()));
        }
        else {
            _simpleManagers.push_back(std::move(manager));
            Logger::Log(std::format("Register {} simple manager", typeid(T).name()));
        }
    }

    template <class T>
    T* ManagersController::GetManager() const
    {
        const auto typeIndex = std::type_index(typeid(T));
        auto it = _mappedManagers.find(typeIndex);
        if (it != _mappedManagers.end()) {
            return static_cast<T*>(it->second);
        }
        return nullptr;
    }
}
