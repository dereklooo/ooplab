//
// Created by Benson on 2025/4/19.
//

#ifndef MUSHROOM_ITEM_HPP
#define MUSHROOM_ITEM_HPP
#include "Object/ItemObject.hpp"
class Mushroom_Item final : public ItemObject {
public:
    explicit Mushroom_Item(const glm::vec2 &position) : ItemObject(position,RESOURCE_DIR"/image/character/Item/Mushroom.png") {

    };
    void Action() override {
        const float DeltaTime = (Util::Time::GetElapsedTimeMs() - LastTime) / 1000.0f;
        switch(state) {
            case ItemState::Hidden:
                break;
            case ItemState::Collected:
                break;
            case ItemState::Walking:
                if(this->way == Left) {
                    this->SetPosition({this->GetPosition().x - 1.5,this->GetPosition().y});
                }
                else if(this->way == Right) {
                    this->SetPosition({this->GetPosition().x + 1.5,this->GetPosition().y});
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
    void ChangeMarioState(std::shared_ptr<Mario>& mario) override {
        if(mario->GetType() == Small) {
            mario->SetType(Big);
            mario->UpDateCurrentState(Stand);
        }
    }
};
#endif //MUSHROOM_ITEM_HPP
