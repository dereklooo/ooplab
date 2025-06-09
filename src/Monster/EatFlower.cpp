//
// Created by benson on 2025/5/22.
//
#include "Core/Shader.hpp"
#include "Monsters/Eat_flower.hpp"
#include <iostream>
EatFlower::EatFlower(glm::vec2 position,std::shared_ptr<Mario>& Mario) : Monster(2,RESOURCE_DIR"/image/character/monster/EatFlower/EatFlower") {
    this->type = Eat_flower;
    this->mario = Mario;
    this->SetZIndex(100);
    this->SetPosition(position);
    this->SetWCollision(false);
    this->OriginalPosition = position;
    this->delta = Util::Time::GetElapsedTimeMs();
    this->SetSize({1.5,1.5});
}
void EatFlower::Hurt() {
    (void) nullptr;
}

void EatFlower::Action() {
    if(this->Die == false) {
        float Time = Util::Time::GetElapsedTimeMs() - this->delta;
        this->SetGravity(0);
        if(Time <= 1000) {
            this->SetPosition(this->OriginalPosition);
        }
        else if(Time <= 2500) {
            this->SetPosition({this->GetPosition().x,this->GetPosition().y + 10 * Util::Time::GetDeltaTimeMs() / 100});
        }
        else if(Time <= 3500) {
            this->SetPosition({OriginalPosition.x,OriginalPosition.y + 85});
        }
        else if(Time <= 4500) {
            this->SetPosition({this->GetPosition().x,this->GetPosition().y - 3.5 * Util::Time::GetDeltaTimeMs() / 100});
        }
        else if(Time <= 5500) {
            this->delta = Util::Time::GetElapsedTimeMs();
        }
        if(mario->GetPosition().x >= 0) {
            this->OriginalPosition.x -= 5.5;
        }
    }
    else {
        if(this->GetKnockAway()) {
            this->SetZIndex(50);
            return;
        }
        else if(Util::Time::GetElapsedTimeMs() - this->StartHurtTimer >= 1000.0f) {
            this->SetPosition({this->GetPosition().x,this->GetPosition().y-500});
        }
    }
}
glm::vec2 EatFlower::GetOriginalPosition() const {
    return this->OriginalPosition;
}
void EatFlower::SetOriginalPosition(const glm::vec2 Pos){
    this->OriginalPosition = Pos;
}

