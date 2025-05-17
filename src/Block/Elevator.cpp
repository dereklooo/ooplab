//
// Created by benson on 2025/5/17.
//
#include "Block/Elevator.hpp"
Elevator::Elevator(const glm::vec2 &position) : SceneObject(RESOURCE_DIR"/image/Background/Level2/Block/Elevator.png", position){

}
void Elevator::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}

void Elevator::Move() {
    if(this->way == Left) {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y - 1.5});
    }
    else {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y + 1.5});
    }
    if (this->GetPosition().y >= 800) {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y - 800.0f});
    }
    else if(this->GetPosition().y <= 800){
        this->SetPosition({this->GetPosition().x,this->GetPosition().y + 800.0f});
    }
}
