#include <Managers/ManagersController.h>
#include <Managers/BaseManagers/RenderManager.h>
#include <Managers/BaseManagers/UpdateManager.h>
#include <Managers/BaseManagers/PlayerWindowInputManager.h>
#include <Messenger/Events/Common.h>
#include <Time/TimeManager.h>

namespace shen3
{
    void ManagersController::Init(Engine* engine)
    {
        _engine = engine;
        InitSubscriptions();
    }

    void ManagersController::AddManager(std::unique_ptr<Manager>&& manager)
    {
        manager->Init(this);

        _mappedManagers[manager->GetTypeIndex()] = manager.get();
        _registrationOrderedManagers.push_back(manager.get());

        if (auto timeManager = dynamic_cast<TimeManager*>(manager.get())) {
            _timeManager = timeManager;
        }

        if (auto playerInputManager = dynamic_cast<PlayerWindowInputManager*>(manager.get())) {
            _playerInputManager = playerInputManager;
        }

        if (dynamic_cast<RenderManager*>(manager.get())){
            RenderManager* renderManager = static_cast<RenderManager*>(manager.release());
            _renderManagers.push_back(std::unique_ptr<RenderManager>(renderManager));
            Logger::Log(std::format("Register {} render manager", renderManager->GetTypeName()));
        }
        else if (dynamic_cast<UpdateManager*>(manager.get())) {
            UpdateManager* updateManager = static_cast<UpdateManager*>(manager.release());
            _updateManagers.push_back(std::unique_ptr<UpdateManager>(updateManager));
            Logger::Log(std::format("Register {} update manager", updateManager->GetTypeName()));
        }
        else {
            Logger::Log(std::format("Register {} simple system", manager->GetTypeName()));
            _simpleManagers.push_back(std::move(manager));
        }
    }

    void ManagersController::Load()
    {
        for (auto& system : _registrationOrderedManagers) {
            system->Load();
        }
    }

    void ManagersController::Start()
    {
        for (auto& system : _registrationOrderedManagers) {
            system->Start();
        }
    }

    void ManagersController::Update()
    {
        for (auto& system : _updateManagers) {
            system->Update();
        }
    }

    void ManagersController::Draw()
    {
        for (auto& system : _renderManagers) {
            system->Draw();
        }
    }

    void ManagersController::Save()
    {
        for (auto& system : _registrationOrderedManagers) {
            system->Save();
        }
    }

    void ManagersController::Stop()
    {
        for (auto& system : _registrationOrderedManagers) {
            system->Stop();
        }
    }

    void ManagersController::Clear()
    {
        Logger::Log("[ManagersController::Clear]");
        _updateManagers.clear();
        _renderManagers.clear();
        _mappedManagers.clear();
        _registrationOrderedManagers.clear();
    }

    float ManagersController::GetDt() const
    {
        if (_timeManager) {
            return _timeManager->Dt();
        }
        return 0.f;
    }

    float ManagersController::GetGameDt() const
    {
        if (_timeManager) {
            return _timeManager->GameDt();
        }
        return 0.f;
    }

    void ManagersController::InitSubscriptions()
    {
        _subscriptions.Reset();

        _subscriptions.Subscribe<LostFocus>([this](const auto&){
            OnLostFocus();
        });

        _subscriptions.Subscribe<GainedFocus>([this](const auto&){
            OnGainedFocus();
        });
    }

    void ManagersController::OnLostFocus()
    {
        for (auto system : _registrationOrderedManagers) {
            system->AppDeactivated();
        }
    }

    void ManagersController::OnGainedFocus()
    {
        for (auto system : _registrationOrderedManagers) {
            system->AppActivated();
        }
    }
}
