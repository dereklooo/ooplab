//
// Created by Benson on 2025/3/20.
//
#include "Monsters/Turtle.hpp"
void Turtle::Action() {
    if(!Die) {
        if(this->way == Way::Left) {
            this->SetPosition({this->GetPosition().x - 1.5,this->GetPosition().y});
            this->SetSize({-3,2.5});
        }
        else if(this->way == Way::Right) {
            this->SetPosition({this->GetPosition().x + 1.5,this->GetPosition().y});
            this->SetSize({3,2.5});
        }
    }
    else if(Util::Time::GetElapsedTimeMs() - this->DieTimer >= 1000.0f) {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y-500});
    }
}
void Turtle::Hurt() {
    this->SetDrawable(this->die->GetDrawable());
    this->Die = true;
}
