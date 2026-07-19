#include <Engine/Engine.h>

#include <Managers/ManagersController.h>
#include <Managers/ManagersFactory.h>
#include <Logger/Logger.h>
#include <Messenger/Events/Common.h>

namespace shen3
{
	Engine::Engine() = default;
	Engine::~Engine() = default;

	void Engine::Initialize()
	{
		InitSubscriptions();
		const bool loaded = CreateManagers();
		SetRunning(loaded);

		if (IsRunning()) {
			LoadManagers();
			InitManagers();
			SetupManagers();
		}
	}

	void Engine::Run()
	{
		while (_isRunning) {
			Update();
		}
	}

	void Engine::Destroy()
	{
		_managers->Clear();
	}

	bool Engine::IsRunning() const
	{
		return _isRunning;
	}

	void Engine::InitSubscriptions()
	{
		_subscriptions.Subscribe<Quit>([this](const auto&) {
			SetRunning(false);
		});
	}

	bool Engine::CreateManagers()
	{
		const bool loaded = _managersLoader.Load();
		if (loaded) {
			_managers = std::make_unique<ManagersController>();
			for (const auto& managerType : _managersLoader.GetManagersList()){
				_managers->AddManager(ManagersFactory::Instance().Get(managerType));
			}
		}
		return loaded;
	}

	void Engine::LoadManagers()
	{
		_managers->Load();
	}

	void Engine::InitManagers()
	{
		_managers->Init(this);
	}

	void Engine::SetupManagers()
	{
		_managers->Start();
	}

	void Engine::Update()
	{
		_managers->Update();
		_managers->Draw();
	}

	void Engine::SetRunning(bool running)
	{
		_isRunning = running;
	}
}
