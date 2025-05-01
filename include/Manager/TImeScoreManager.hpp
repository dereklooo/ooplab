//
// Created by benson on 2025/5/1.
//

#ifndef TIMESCOREMANAGER_HPP
#define TIMESCOREMANAGER_HPP
#include "Mario/Mario.hpp"
#include "TimeScore/Score.hpp"
#include "TimeScore/Timer.hpp"
class TimeScoreManager {
    public:
        explicit TimeScoreManager(std::shared_ptr<Mario> &Mario,std::shared_ptr<Score> &Score,std::shared_ptr<Timer> &Timer);
        void update() const;
        float GetTimer() const;
        int GetScore() const;
    private:
        std::shared_ptr<Mario>& Mario_;
        std::shared_ptr<Score> Score_;
        std::shared_ptr<Timer> Timer_;
};
#endif //TIMESCOREMANAGER_HPP
