//
// Created by benson on 2025/5/27.
//
#include "Trap/KooperFireBall.hpp"
KooperFireBall::KooperFireBall(const std::shared_ptr<Mario>& mario,const glm::vec2 Pos) : AnimationObject(2,RESOURCE_DIR"/image/character/monster/kooper/KooperFireBall"){
    this->mario = mario;
    this->SetPosition(Pos);
    this->SetSize({3,3});
    this->SetZIndex(100);
}
void KooperFireBall::Action() {
    if(this->GetPosition().y <= mario->GetPosition().y) {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y + 100 *Util::Time::GetDeltaTimeMs() /1000});
    }
    if(this->GetPosition().y >= mario->GetPosition().y) {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y - 100 *Util::Time::GetDeltaTimeMs() /1000});
    }
    if (mario->GetPosition().x >= 0) {
        this->SetPosition({this->GetPosition().x - 4,this->GetPosition().y});
    }
    this->SetPosition({this->GetPosition().x - 200 * Util::Time::GetDeltaTimeMs() / 1000,this->GetPosition().y});
}
