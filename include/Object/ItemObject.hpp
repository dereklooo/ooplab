//
// Created by Benson on 2025/4/19.
//

#ifndef ITEMOBJECT_HPP
#define ITEMOBJECT_HPP
#include "Object/StillObject.hpp"
class ItemObject : public StillObject {
public:
    ItemObject(const glm::vec2 &position,const std::string &ImagePath) : StillObject(ImagePath) {
        this->SetPosition(position);
    };
    virtual void Action() = 0;
protected:
    Way way = Right;
};
#endif //ITEMOBJECT_HPP