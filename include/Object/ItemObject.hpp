//
// Created by Benson on 2025/4/19.
//

#ifndef ITEMOBJECT_HPP
#define ITEMOBJECT_HPP
#include "Object/StillObject.hpp"
enum ItemState {
    Hidden,
    PoppingUp,
    Walking,
    Collected
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

    void SetState(ItemState state) {
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
protected:
    ItemState state = Hidden;
    float StartPopTime = 0.0f;
    float LastTime = 0;

    Way way = Right;
};
#endif //ITEMOBJECT_HPP