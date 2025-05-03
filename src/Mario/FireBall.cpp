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
}

void FireBall::Rolling() {
    if(this->way == Right) {
        this->SetPosition({this->GetPosition().x + 4,this->GetPosition().y,});
    }
    else {
        this->SetPosition({this->GetPosition().x - 4,this->GetPosition().y,});
    }

    if(!this->GetFalling()) {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y + 5});
        this->SetGravity(-4.0f);
    }
}
void FireBall::Explode() {
    const auto temp = FireBall::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/fire/fireball/explode",200,100);
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
