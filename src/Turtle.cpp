//
// Created by Benson on 2025/3/20.
//
#include "Monsters/Turtle.hpp"
void Turtle::Action() {
    if(this->way == Way::left) {
        this->SetPosition({this->GetPosition().x - 1,this->GetPosition().y});
    }
    else if(this->way == Way::right) {
        this->SetPosition({this->GetPosition().x + 1,this->GetPosition().y});
    }
}
void Turtle::GotHit() {

}
