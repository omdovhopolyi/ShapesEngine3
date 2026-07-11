#pragma once

#include <Messenger/SubscriptionsContainer.h>
#include <Managers/ManagersListLoader.h>

#include <memory>

namespace shen3
{
	class ManagersController;

	class Engine
	{
	public:
		Engine();
		~Engine();

		void Initialize();
		void Run();
		void Destroy();

		bool IsRunning() const;

	private:
		void InitSubscriptions();
		bool CreateManagers();
		void LoadManagers();
		void InitManagers();
		void SetupManagers();
		void Update();

		void SetRunning(bool running);

	private:
		bool _isRunning = false;
		SubcriptionsContainer _subscriptions;
		std::unique_ptr<ManagersController> _managers;
		ManagersListLoader _managersLoader;
	};
}
