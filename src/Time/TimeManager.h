#pragma once

#include <Managers/BaseManagers/UpdateManager.h>

#include <chrono>

namespace shen3
{
    class TimeManager
        : public UpdateManager
    {
        MANAGERS_FACTORY(TimeManager)

    public:
        void Start();
        void Update();
        float Dt() const;
        int DtMs() const;
        float GameDt() const;
        int GameDtMs() const;

        void PauseGame(bool pause);
        bool IsGamePaused() const;

        void SetGameTimeScale(float scale);
        float GetGameTimeScale() const;

        const std::chrono::time_point<std::chrono::high_resolution_clock>& GetLastUpdateTime() { return _lastUpdateTime; }

    private:
        void CalculateDt();
        void UpdateGameTime();

    private:
        float _dt = 0.f;
        float _gameDt = 0.f;
        float _uiDt = 0.f;
        float _gameTimeScale = 1.f;
        int _gamePausedCounter = 0;
        std::chrono::time_point<std::chrono::high_resolution_clock> _lastUpdateTime;
    };
}
