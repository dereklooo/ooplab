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

    bool IsInside() const {
        return Inside;
    }
    void SetInside(const bool inside) {
        Inside = inside;
    }

    void SetSpawn(const bool spawn) {
        this->Spawning = spawn;
    }
    bool IsSpawning() const {
        return Spawning;
    }

    void SetStartSpawningTime(const float Start) {
        this->StartSpawningTime = Start;
    }
protected:
    bool Spawning = false;
    bool Inside = true;
    float StartSpawningTime = 0;
    Way way = Right;
};
#endif //ITEMOBJECT_HPP