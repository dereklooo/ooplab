//
// Created by Benson on 2025/3/20.
//
#include "Monsters/Turtle.hpp"
void Turtle::Action() {
    if(Turtle_type == OutSize) {
        if(this->way == Way::Left) {
            this->SetPosition({this->GetPosition().x - 1.5,this->GetPosition().y});
            this->SetSize({-3,2.5});
        }
        else if(this->way == Way::Right) {
            this->SetPosition({this->GetPosition().x + 1.5,this->GetPosition().y});
            this->SetSize({3,2.5});
        }
    }
    else if(Turtle_type == Inside) {

    }
    else if(Turtle_type == Rolling) {
        if(this->way == Way::Left) {
            this->SetPosition({this->GetPosition().x - 5,this->GetPosition().y});
            this->SetSize({-3,2.5});
        }
        else if(this->way == Way::Right) {
            this->SetPosition({this->GetPosition().x + 5,this->GetPosition().y});
            this->SetSize({3,2.5});
        }
    }

}
void Turtle::Hurt() {
    if(!Die) {
        this->Die = true;
        this->SetDrawable(this->die->GetDrawable());
    }
    else {

    }
}
