//
// Created by benson on 2025/5/2.
//
#include "Item/FireFlower_Item.hpp"


FireFlower::FireFlower(const glm::vec2 &position) : ItemObject(position,RESOURCE_DIR"Resources/image/character/Item/Fire.png"){

}
void FireFlower::Action() {
    const float DeltaTime = (Util::Time::GetElapsedTimeMs() - LastTime) / 1000.0f;
    switch(state) {
        case ItemState::Hidden:
            break;
        case ItemState::Collected:
            break;
        case ItemState::Walking:
            return;
        break;
        case ItemState::PoppingUp:
            this->SetWCollision(false);
        this->SetPosition({this->GetPosition().x,this->GetPosition().y + DeltaTime * 0.1f});
        if(Util::Time::GetElapsedTimeMs() - StartPopTime >= 90) {
            this->SetWCollision(true);
            this->state = Walking;
            this->SetGravity(0.0f);
            this->SetWay(Right);
        }
        break;
    }
    LastTime = Util::Time::GetElapsedTimeMs();
}
void FireFlower::ChangeMarioState(std::shared_ptr<Mario> &mario) {
    if(mario->GetType() == Small || mario->GetType() == Big) {
        mario->SetType(Fire);
        mario->UpDateCurrentState(Stand);
    }
}

