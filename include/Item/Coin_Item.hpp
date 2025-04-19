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
            if(Spawning) {
                this->SetVisible(true);
                if(Util::Time::GetElapsedTimeMs() - this->StartSpawningTime <= 2000) {
                    this->SetGravity(-2.5f);
                }
                else if(Util::Time::GetElapsedTimeMs() - this->StartSpawningTime <= 4000){
                    this->SetGravity(2.5f);
                }
                else if(Util::Time::GetElapsedTimeMs() - this->StartSpawningTime > 4000) {
                    this->SetGravity(0.0f);
                    this->Spawning = false;
                    this->Inside = true;
                }
            }
        }
};
#endif //COIN_ITEM_HPP
