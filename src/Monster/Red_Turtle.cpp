//
// Created by 羅健文 on 2025/6/2.
//
#include "Monsters/Red_Turtle.hpp"

#include <iostream>
#include <ostream>

void RedTurtle::Action() {
    //std::cout << this->Turtle_type << std::endl;
    if(this->Die == false) {
        if(Turtle_type == OutSide) {
            if(this->way == Way::Left) {
                this->SetPosition({this->GetPosition().x - 1.5,this->GetPosition().y});
                this->SetSize({-1.3,1.25});
            }
            else if(this->way == Way::Right) {
                this->SetPosition({this->GetPosition().x + 1.5,this->GetPosition().y});
                this->SetSize({1.3,1.25});
            }

            if (this->GetFalling() ) {
                if (  this->GetWay()==Left ) {
                    //std::cout<<"2"<< std::endl;
                    this->SetWay(Right);
                    this->SetPosition({this->GetPosition().x + 3,this->GetPosition().y+1.55});

                }
                else if ( this->GetWay()==Right) {
                    // std::cout<<"3"<< std::endl;
                    this->SetWay(Left);
                    this->SetPosition({this->GetPosition().x - 3,this->GetPosition().y+1.55});

                }
            }
        }
        else if(Turtle_type == Inside) {
            if(Util::Time::GetElapsedTimeMs() - StartHurtTimer >= 5000 && Util::Time::GetElapsedTimeMs() - StartHurtTimer < 10000) {
                this->SetDrawable(DieDrawable2);
            }
            if(Util::Time::GetElapsedTimeMs() - StartHurtTimer >= 10000) {
                this->SetDrawable(WalkDrawable);
                this->Turtle_type = OutSide;
            }
            this->SetSize({1.3,1.25});
        }
        else if(Turtle_type == Rolling) {
            if(this->way == Way::Left) {
                this->SetPosition({this->GetPosition().x - 5,this->GetPosition().y});
                this->SetSize({-1.3,1.25});
            }
            else if(this->way == Way::Right) {
                this->SetPosition({this->GetPosition().x + 5,this->GetPosition().y});
                this->SetSize({1.3,1.25});
            }
        }
    }
    else {
        return;
    }








}

void RedTurtle::Hurt() {
    if(Turtle_type == OutSide) {
        this->SetDrawable(this->DieDrawable1);
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
    std::cout << this->Turtle_type << std::endl;
}