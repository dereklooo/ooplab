//
// Created by 羅健文 on 2025/4/11.
//

#include "Mario/Mario.hpp"

#include <ostream>
#include <unistd.h>
#include <iostream>
#include "Mario/Mario_small.hpp"

void Mario::rightMove() {
    if (GetAcceleration()<=4.0f && GetAcceleration()>=0.0f) {
        SetAcceleration(GetAcceleration()+0.1f);
        if (GetAcceleration()>4.0) {
            SetAcceleration(4.0);
        }

        this->SetSize({1.35,1.2});
        CurrentState = 0;
    }else if (GetAcceleration()<0) {
        SetAcceleration(GetAcceleration()+0.2f);
        CurrentState=3;
        this->SetSize({1.35,1.2});
    }
    this->SetPosition({this->GetPosition().x + GetAcceleration(),this->GetPosition().y});

}
void Mario::leftMove() {
    if(this->GetPosition().x - 1 <= -620) {
        this->SetPosition({-620,this->GetPosition().y});
    }
    else {
        if (GetAcceleration()>=-4.0f && GetAcceleration()<=0.0f) {
            SetAcceleration(GetAcceleration()-0.1f);
            if (GetAcceleration()<-4.0) {
                SetAcceleration(-4.0);
            }

            this->SetSize({-1.35,1.2});
            CurrentState = 0;
        }else {
            SetAcceleration(GetAcceleration()-0.2f);
            CurrentState=3;
            this->SetSize({-1.35,1.2});
        }

    }

    this->SetPosition({this->GetPosition().x + GetAcceleration(),this->GetPosition().y});

}
void Mario::jump() {
    if(!this->GetFalling()) {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y + 4});
        this->SetGravity(-15);
    }
}

void Mario::brakes() {

    if(!Util::Input::IsKeyPressed(Util::Keycode::S) &&
    !Util::Input::IsKeyPressed(Util::Keycode::W) &&
    !Util::Input::IsKeyPressed(Util::Keycode::A) &&
    !Util::Input::IsKeyPressed(Util::Keycode::D)) {
        if (GetAcceleration()>=0.07f ) {
            SetAcceleration(GetAcceleration()-0.07);
            this->SetPosition({this->GetPosition().x + GetAcceleration(),this->GetPosition().y});
        }else if (GetAcceleration()<=-0.02f) {
            SetAcceleration(GetAcceleration()+0.07);
            this->SetPosition({this->GetPosition().x + GetAcceleration(),this->GetPosition().y});
        }
        else{SetAcceleration(0);}


    }
}