//
// Created by benson on 2025/5/1.
//

#ifndef TIMESCOREMANAGER_HPP
#define TIMESCOREMANAGER_HPP
#include "Mario/Mario.hpp"
#include "Util/Renderer.hpp"
#include "TImeAndScore/Score.hpp"
#include "TImeAndScore/Timer.hpp"

class TimeScoreManager {
    public:
        explicit TimeScoreManager(const std::shared_ptr<Mario> &Mario,float GameStartTime,int* Live);
        void Update() const;
        float GetTimer() const;
        int GetScore() const;
        void TimeScoreManagerInitialize(const std::shared_ptr<Util::Renderer> &renderer);
    private:
        float GameStartTime;
        int Score_;
        std::shared_ptr<Mario> Mario_;
        std::vector<std::shared_ptr<Score>> Scores;
        std::vector<std::shared_ptr<Timer>> Timers;
    int* Lives;

};
#endif //TIMESCOREMANAGER_HPP
