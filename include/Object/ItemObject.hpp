//
// Created by Benson on 2025/4/19.
//

#ifndef ITEMOBJECT_HPP
#define ITEMOBJECT_HPP
#include "Object/StillObject.hpp"
#include "Mario/Mario.hpp"
enum ItemState {
    Hidden,
    PoppingUp,
    Walking,
    Collected
};
enum ItemType {
    Item_Mushroom,
    Item_FireFlower,
    Item_Star,
    Item_Coin
};
class ItemObject : public StillObject {
public:
    ItemObject(const glm::vec2 &position,const std::string &ImagePath) : StillObject(ImagePath) {
        this->SetPosition(position);
    };
    virtual void Action() = 0;

    ItemState GetState() const {
        return state;
    }

    void SetState(const ItemState state) {
        this->state = state;
    }
    void SetStartPopTime(const float t) {
        StartPopTime = t;
    }
    float GetStartPopTime() const {
        return StartPopTime;
    }
    Way GetWay() const {
        return way;
    }
    void SetWay(const Way way){
        this->way = way;
    }
    ItemType GetType() const {
        return type;
    }
    virtual void ChangeMarioState(std::shared_ptr<Mario> &mario) = 0;
protected:
    float StartPopTime = 0.0f;
    float LastTime = 0;

    ItemState state = Hidden;
    ItemType type;
    Way way = Right;

};
#endif //ITEMOBJECT_HPP