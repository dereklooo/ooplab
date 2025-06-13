//
// Created by benson on 2025/5/1.
//
#include "Manager/TimeScoreManager.hpp"

#include <iostream>
#include <ostream>

TimeScoreManager::TimeScoreManager(const std::shared_ptr<Mario> &Mario, const float GameStartTime,int* Live) :
GameStartTime(GameStartTime),
Score_(0),
Mario_(Mario),
Lives( Live){
    for (int i = 0;i < 5 ; i++) {
        auto temp2 = std::make_shared<Timer>();
        temp2->SetPosition({-75 + 30 * i,340});
        temp2->SetOriginPosition({-75 + 30 * i,340});
        temp2->SetSize({1.5,2});
        temp2->SetZIndex(100);
        Timers.push_back(temp2);
    }

    for (int i = 0;i < 4 ; i++) {
        auto temp2 = std::make_shared<Score>();
        temp2->SetPosition({145 + 30 * i,340});
        temp2->SetSize({1.25,1.75});
        temp2->SetZIndex(100);
        Scores.push_back(temp2);
    }
    auto temp2 = std::make_shared<Score>();
    temp2->SetPosition({145 + 30 * 5,340});
    temp2->SetSize({1.5,2});
    temp2->SetZIndex(100);
    Scores.push_back(temp2);


}

void TimeScoreManager::Update() const {
    const float timer = this->GetTimer() / 1000;
    for (int i = 4;i >= 0 ; i--) {
        int temp = static_cast<int>(timer /pow(10,i));
        this->Timers[4 - i]->SetPosition(Timers[4-i]->GetOriginPosition());
        this->Timers[4 - i]->SetTime(temp % 10);
    }
    for (int i = 0;i < 4 ; i++) {
        this->Scores[i]->SetScore(10+i);
    }
    if (Lives != NULL) {Scores[4]->SetScore(*Lives);}


}

float TimeScoreManager::GetTimer() const {
    return Util::Time::GetElapsedTimeMs() - GameStartTime;
}

int TimeScoreManager::GetScore() const {
    return Mario_->GetScore();
}
void TimeScoreManager::TimeScoreManagerInitialize(const std::shared_ptr<Util::Renderer> &renderer) {
    for(auto& score : Scores) {
        renderer->AddChild(score);
    }
    for (auto& timer : Timers) {
        renderer->AddChild(timer);
    }
}
