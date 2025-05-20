//
// Created by benson on 2025/5/17.
//
#include "Block/Elevator.hpp"
Elevator::Elevator(const glm::vec2 &position, const Way way) : SceneObject(RESOURCE_DIR"/image/Background/Level2/Block/Elevator.png", position){
    this->way = way;
}
void Elevator::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}

void Elevator::Move() {
    if(this->GetPosition().x <= 1000) {
        this->Moving = true;
    }
    if(this->Moving == true) {
        if(this->way == Left) {
            this->SetPosition({this->GetPosition().x,this->GetPosition().y - 3});
        }
        else {
            this->SetPosition({this->GetPosition().x,this->GetPosition().y + 3});
        }
        if (this->GetPosition().y >= 500) {
            this->SetPosition({this->GetPosition().x,-499.0f});
        }
        else if(this->GetPosition().y <= -500){
            this->SetPosition({this->GetPosition().x,499.0f});
        }
    }
}
