//
// Created by benson on 2025/5/17.
//

#include "Block/HorizontalElevator.hpp"
HorizontalElevator::HorizontalElevator(const glm::vec2 &position) : SceneObject(RESOURCE_DIR"/image/Background/Level2/Block/Elevator.png", position){


}
void HorizontalElevator::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}

void HorizontalElevator::Move() {
    if(this->way == Way::Left) {
      this->SetPosition({this->GetPosition().x-3, this->GetPosition().y});
      this->movecenter -= 3;
      if(movecenter <= 0) {
        this->way = Way::Right;
        this->movecenter = MoveLong*2;
      }
    }
    else if(this->way == Way::Right) {
        this->SetPosition({this->GetPosition().x+3, this->GetPosition().y});
        this->movecenter -= 3;
        if(this->movecenter <= 0) {
            this->way = Way::Left;
            this->movecenter = MoveLong*2;
        }
    }
}
