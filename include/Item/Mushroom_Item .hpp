//
// Created by Benson on 2025/4/19.
//

#ifndef MUSHROOM_ITEM_HPP
#define MUSHROOM_ITEM_HPP
#include "Object/ItemObject.hpp"
class Mushroom_Item final : public ItemObject {
public:
    Mushroom_Item(const glm::vec2 &position,const std::string &ImagePath) : ItemObject(position,ImagePath) {

    };
    void Action() override {
        if(this->way == Right) {
            this->SetPosition({this->GetPosition().x + 4,this->GetPosition().y});
        }
        else if(this->way == Left){
            this->SetPosition({this->GetPosition().x - 4,this->GetPosition().y});
        }
    }

};
#endif //MUSHROOM_ITEM_HPP
