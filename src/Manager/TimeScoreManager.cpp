//
// Created by benson on 2025/5/1.
//
#include "Manager/TimeScoreManager.hpp"
TimeScoreManager::TimeScoreManager(std::shared_ptr<Mario> &Mario,std::shared_ptr<Score> &Score,std::shared_ptr<Timer> &Timer) :
Mario_(Mario),
Score_(Score),
Timer_(Timer){

}

void TimeScoreManager::update() const {
    Score_->SetScore(Mario_->GetScore());
    Timer_->SetTime(Util::Time::GetElapsedTimeMs());
}

float TimeScoreManager::GetTimer() const {
    return Timer_->GetTime();
}

int TimeScoreManager::GetScore() const {
    return Score_->GetScore();
}
