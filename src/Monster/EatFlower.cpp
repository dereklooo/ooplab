//
// Created by benson on 2025/5/22.
//
#include "Core/Shader.hpp"
#include "Monsters/Eat_flower.hpp"
EatFlower::EatFlower(glm::vec2 position) : Monster(2,RESOURCE_DIR"/image/character/monster/EatFlower/EatFlower") {
    this->type = Eat_flower;
    this->SetZIndex(100);
    this->SetPosition(position);
    this->delta = Util::Time::GetElapsedTimeMs();
}
void EatFlower::Hurt() {
    (void) nullptr;
}

void EatFlower::Action() {
    delta = Util::Time::GetElapsedTimeMs() - this->delta;
    this->SetGravity(0);
    if(delta <= 5000) {
        this->side = In;
    }
    else if(delta <= 10000) {
        this->side = Out;
        delta = Util::Time::GetElapsedTimeMs();
    }
    if(this->Die) {
        return;
    }
    else {
        if(this->side == Out) {
            this->SetGravity(-2);
        }
        if(this->side == In) {
            this->SetGravity(2);
        }
    }
}
