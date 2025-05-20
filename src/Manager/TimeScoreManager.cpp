//
// Created by benson on 2025/5/1.
//
#include "Manager/TimeScoreManager.hpp"
TimeScoreManager::TimeScoreManager(const std::shared_ptr<Mario> &Mario, const float GameStartTime) :
GameStartTime(GameStartTime),
Score_(0),
Mario_(Mario){
    for (int i = 0;i < 5 ; i++) {
        auto temp1 = std::make_shared<Score>();
        temp1->SetPosition({300- 30 * i,300});
        temp1->SetSize({0.6,0.6});
        Scores.push_back(temp1);

        auto temp2 = std::make_shared<Timer>();
        temp2->SetPosition({-300 + 30 * i,300});
        temp2->SetSize({0.6,0.6});
        Timers.push_back(temp2);
    }
}

void TimeScoreManager::update() const {

}

float TimeScoreManager::GetTimer() const {
    return Util::Time::GetElapsedTimeMs() - GameStartTime;
}

int TimeScoreManager::GetScore() const {
    return Score_;
}
void TimeScoreManager::TimeScoreManagerInitialize(const std::shared_ptr<Util::Renderer> &renderer) {
    for(auto& score : Scores) {
        renderer->AddChild(score);
    }
    for (auto& timer : Timers) {
        renderer->AddChild(timer);
    }
}
