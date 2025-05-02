//
// Created by benson on 2025/5/2.
//
#include "Mario/FireBall.hpp"


FireBall::FireBall(const glm::vec2 position) : AnimationObject(4,RESOURCE_DIR"/image/character/mario/fire/fireball/Rollingfireball1.png"){
    this->SetSize({1.5,1.5});
    this->SetPosition(position);
}

void FireBall::Rolling() {
    if(!this->GetFalling()) {
        this->SetGravity(-2.0f);
        this->SetPosition({this->GetPosition().x + 4,this->GetPosition().y,});
    }
}
void FireBall::Explode() {
    auto temp = std::dynamic_pointer_cast<Util::Animation>(this->GetDrawable());
    if(temp->GetState() == Util::Animation::State::ENDED) {
        this->SetState(FireBallState::Rolling);
    }
}
void FireBall::SetState(const FireBallState state) {
    this->state = state;
}
FireBallState FireBall::GetState() const {
    return this->state;
}
