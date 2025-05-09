//
// Created by benson on 2025/5/2.
//
#include "Mario/FireBall.hpp"

#include <iostream>
#include <ostream>

#include "Util/Keycode.hpp"


FireBall::FireBall(const glm::vec2 position) : AnimationObject(4,RESOURCE_DIR"/image/character/mario/fire/fireball/Rollingfireball"){
    this->SetSize({1.5,1.5});
    this->SetPosition(position);
    this->SetZIndex(20);
    this->SetVisible(true);
    this->SetFallingTime(Util::Time::GetElapsedTimeMs());
    this->SetGravity(0);
}

void FireBall::Rolling() {
    if(this->way == Right) {
        this->SetPosition({this->GetPosition().x + 8,this->GetPosition().y,});
    }
    else {
        this->SetPosition({this->GetPosition().x - 8,this->GetPosition().y,});
    }

}
void FireBall::Explode(const float Time) {
    const auto temp = explode;
    this->StartExplodeTime = Time;
    this->SetDrawable(temp);
    this->SetState(FireBallState::End);
}
void FireBall::SetState(const FireBallState state) {
    this->state = state;
}
void FireBall::SetWay(const Way way) {
    this->way = way;
}

Way FireBall::GetWay() const {
    return way;
}
FireBallState FireBall::GetState() const {
    return this->state;
}
float FireBall::GetStartExplodeTime() const {
    return StartExplodeTime;
}
