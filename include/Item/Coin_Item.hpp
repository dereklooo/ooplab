//
// Created by Benson on 2025/4/19.
//

#ifndef COIN_ITEM_HPP
#define COIN_ITEM_HPP
#include <iostream>
#include <ostream>

#include "Object/ItemObject.hpp"
class Coin_Item : public ItemObject {
    public:
        explicit Coin_Item(const glm::vec2 &position) : ItemObject(position,RESOURCE_DIR"/image/character/Item/Coin.png") {

        };
        void Action() override {
            this->SetGravity(0.0f);
            const float DeltaTime = (Util::Time::GetElapsedTimeMs() - LastTime) / 1000.0f;
            switch(state) {
                case ItemState::Hidden:
                    break;
                case ItemState::Collected:
                    this->SetPosition({this->GetPosition().x,this->GetPosition().y - DeltaTime * 250.0f});
                    if(Util::Time::GetElapsedTimeMs() - StartPopTime >= 2000) {
                        this->SetVisible(false);
                        this->state = Walking;
                    }
                    break;
                case ItemState::Walking:
                    SetWCollision(true);
                    break;
                case ItemState::PoppingUp:
                    this->SetWCollision(false);
                    this->SetPosition({this->GetPosition().x,this->GetPosition().y + DeltaTime * 250.0f});
                    if(Util::Time::GetElapsedTimeMs() - StartPopTime >= 1000) {
                        this->state = Collected;
                    }
                    break;
            }
            LastTime = Util::Time::GetElapsedTimeMs();
        }
        void ChangeMarioState(std::shared_ptr<Mario> &mario) override{
            (void)mario;
        }
};
#endif //COIN_ITEM_HPP
