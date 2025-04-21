//
// Created by Benson on 2025/4/19.
//

#ifndef COIN_ITEM_HPP
#define COIN_ITEM_HPP
#include "Object/ItemObject.hpp"
class Coin_Item : public ItemObject {
    public:
        explicit Coin_Item(const glm::vec2 &position) : ItemObject(position,RESOURCE_DIR"/image/character/Item/Coin.png") {

        };
        void Action() override {
            float DeltaTime = (Util::Time::GetElapsedTimeMs() - LastTime) / 1000.0f;
            switch(ItemState State) {
                case ItemState::Hidden:
                    break;
                case ItemState::Collected:
                    this->SetPosition({this->GetPosition().x,this->GetPosition().y - DeltaTime * 5.0f});
                    if(Util::Time::GetElapsedTimeMs() - StartPopTime >= 4000) {
                        this->state = Walking;
                    }
                    break;
                case ItemState::Walking:
                    this->SetGravity(0.0f);
                    break;
                case ItemState::PoppingUp:
                    this->SetPosition({this->GetPosition().x,this->GetPosition().y + DeltaTime * 5.0f});
                    if(Util::Time::GetElapsedTimeMs() - StartPopTime >= 2000) {
                        this->state = Collected;
                    }
                    break;
            }
        }
};
#endif //COIN_ITEM_HPP
