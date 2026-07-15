#include <Time/TimeManager.h>
#include <Common/Assert.h>
#include <Logger/Logger.h>

#include <Managers/ManagersController.h>

namespace shen3
{
	REGISTER_MANAGERS_FACTORY(TimeManager)

	void TimeManager::Start()
	{
		_lastUpdateTime = std::chrono::high_resolution_clock::now();
	}

	void TimeManager::Update()
	{
		CalculateDt();
		UpdateGameTime();
	}

	float TimeManager::Dt() const
	{
		return _dt;
	}

	float TimeManager::GameDt() const
	{
		return _gameDt;
	}

	void TimeManager::PauseGame(bool pause)
	{
		std::string msg = "[TimeManager::PauseGame] " + std::to_string(pause);
		Logger::Log(msg);

		if (pause) {
			_gamePausedCounter++;
		}
		else {
			Assert(_gamePausedCounter > 0, "[TimeManager::PauseGame]");
			_gamePausedCounter--;
			if (_gamePausedCounter < 0) {
				_gamePausedCounter = 0;
			}
		}
	}

	bool TimeManager::IsGamePaused() const
	{
		return _gamePausedCounter > 0;
	}

	void TimeManager::SetGameTimeScale(float scale)
	{
		_gameTimeScale = scale;
	}

	float TimeManager::GetGameTimeScale() const
	{
		return _gameTimeScale;
	}

	void TimeManager::CalculateDt()
	{
		auto now = std::chrono::high_resolution_clock::now();
		_dt = (std::chrono::duration_cast<std::chrono::microseconds>(now - _lastUpdateTime).count()) / (1000.f * 1000.f);
		_lastUpdateTime = now;
	}

	void TimeManager::UpdateGameTime()
	{
		_gameDt = IsGamePaused() ? 0.f : (_dt * _gameTimeScale);
	}
}
