//
// Created by benson on 2025/4/29.
//
#include "Item/Star_Item.hpp"
Star_Item::Star_Item(const glm::vec2 &position) : ItemObject(position,RESOURCE_DIR"/image/character/Item/Star.png"){

}

void Star_Item::Action() {
    const float DeltaTime = (Util::Time::GetElapsedTimeMs() - LastTime) / 1000.0f;
    switch(state) {
        case ItemState::Hidden:
            break;
        case ItemState::Collected:
            break;
        case ItemState::Walking:
            if(this->way == Left) {
                this->SetPosition({this->GetPosition().x - 3,this->GetPosition().y});
                if(!this->GetFalling()) {
                    this->SetPosition({this->GetPosition().x,this->GetPosition().y + 3.5f});
                    this->SetGravity(-10.0f);
                }
            }
            else if(this->way == Right) {
                this->SetPosition({this->GetPosition().x + 3,this->GetPosition().y});
                if(!this->GetFalling()) {
                    this->SetPosition({this->GetPosition().x,this->GetPosition().y + 3.5f});
                    this->SetGravity(-10.0f);
                }
            }
            SetWCollision(true);
        break;
        case ItemState::PoppingUp:
            this->SetWCollision(false);
            this->SetPosition({this->GetPosition().x,this->GetPosition().y + DeltaTime * 0.1f});
            if(Util::Time::GetElapsedTimeMs() - StartPopTime >= 90) {
                this->state = Walking;
                this->SetGravity(0.0f);
                this->SetWay(Right);
            }
            break;
    }
    LastTime = Util::Time::GetElapsedTimeMs();
}
void Star_Item::ChangeMarioState(std::shared_ptr<Mario> &mario) {
    mario->SetStaring(true,Util::Time::GetElapsedTimeMs());
    mario->UpDateCurrentState(Stand);
}
