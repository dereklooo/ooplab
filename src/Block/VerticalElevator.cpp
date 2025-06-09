//
// Created by benson on 2025/5/17.
//
#warning "VerticalElevator.cpp is being compiled"
#include "Block/VerticalElevator.hpp"
VerticalElevator::VerticalElevator(const glm::vec2 &position) : SceneObject(RESOURCE_DIR"/image/Background/Level2/Block/Elevator.png", position){
    way=Way::up;


}
void VerticalElevator::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}

void VerticalElevator::Move() {
    if(way == Way::up) {
        this->SetPosition({this->GetPosition().x, this->GetPosition().y+3});
        movecenter -= 3;
        if(movecenter <= 0) {
            way = Way::down;
            movecenter = MoveLong*2;
        }
    }
    else if(way == Way::down) {
        this->SetPosition({this->GetPosition().x, this->GetPosition().y-3});
        movecenter -= 3;
        if(movecenter <= 0) {
            way = Way::up;
            movecenter = MoveLong*2;
        }
    }
}

