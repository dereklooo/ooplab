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
        if(Spawning) {
            this->SetVisible(true);
            if(Util::Time::GetElapsedTimeMs() - this->StartSpawningTime <= 2000) {
                this->SetGravity(-0.5);
            }
            else if(Util::Time::GetElapsedTimeMs() - this->StartSpawningTime > 2000) {
                this->SetGravity(0.0f);
                this->Spawning = false;
            }
        }
        if(!this->IsInside() && !Spawning) {
            if(this->way == Right) {
                this->SetPosition({this->GetPosition().x + 4,this->GetPosition().y});
            }
            else if(this->way == Left){
                this->SetPosition({this->GetPosition().x - 4,this->GetPosition().y});
            }
        }
    }

};
#endif //MUSHROOM_ITEM_HPP
