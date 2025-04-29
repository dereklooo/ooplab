//
// Created by Benson on 2025/3/20.
//
#include "Monsters/Turtle.hpp"
void Turtle::Action() {
    if(this->Die == false) {
        if(Turtle_type == OutSide) {
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
            if(Util::Time::GetElapsedTimeMs() - StartHurtTimer >= 10000) {
                this->SetDrawable(WalkDrawable);
                this->Turtle_type = OutSide;
            }
            this->SetSize({3,2.5});
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
    else {
        return;
    }
}
void Turtle::Hurt() {
    if(Turtle_type == OutSide) {
        this->SetDrawable(this->DieDrawable);
        this->StartHurtTimer = Util::Time::GetElapsedTimeMs();
        this->Turtle_type = Inside;
    }
    else if(Turtle_type == Inside) {
        this->Turtle_type = Rolling;
    }
    else if(Turtle_type == Rolling) {
        this->StartHurtTimer = Util::Time::GetElapsedTimeMs();
        this->Turtle_type = Inside;
    }
}
