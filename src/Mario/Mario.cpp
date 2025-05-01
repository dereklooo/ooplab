//
// Created by 羅健文 on 2025/4/11.
//

#include "Mario/Mario.hpp"

#include <ostream>
#include <unistd.h>
#include <iostream>

    Mario::Mario() : AnimationObject(1,RESOURCE_DIR"/image/character/mario/small/stand/small_stand") {
        this->SmallDrawable.push_back(Mario::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/stand/small_stand",400,100)); // stand
        this->SmallDrawable.push_back(Mario::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/small/run/small_run",80,60)); //run
        this->SmallDrawable.push_back(Mario::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/jump/small_jump",400,100)); // jump
        this->SmallDrawable.push_back(Mario::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/die/die",400,100)); // die
        this->SmallDrawable.push_back(Mario::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/small/SmalltoBig/SmalltoBig",800,200)); //SmallToBig
        this->SmallDrawable.push_back(Mario::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/stop/small_stop",400,100)); //stop

        this->BigDrawable.push_back(Mario::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/stand/stand",100,100)); // stand
        this->BigDrawable.push_back(Mario::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/run/big_run",80,60)); //run
        this->BigDrawable.push_back(Mario::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/jump/big_jump",100,100)); //jump
        this->BigDrawable.push_back(Mario::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/BigToSmall/big_to_small",200,50)); // BigToSmall
        this->BigDrawable.push_back(Mario::GenerateAnimation(2,RESOURCE_DIR"/image/character/mario/big/BigToFire/big_to_fire",800,200)); //BigToFire
        this->BigDrawable.push_back(Mario::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/Down/big_down",800,200)); //down
        this->BigDrawable.push_back(Mario::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/stop/big_stop",800,200)); // stop

        this->SetSize({1.4,1.4});
        this->Type = Small;
    };
void Mario::UpDateCurrentState(const Action act) {
    if(Type == Small) {
        switch(act) {
            case Action::Stand:
                this->SetDrawable(this->SmallDrawable[0]);
            break;
            case Action::Run:
                this->SetDrawable(this->SmallDrawable[1]);
            break;
            case Action::Jump:
                this->SetDrawable(this->SmallDrawable[2]);
            break;
            case Action::Die:
                this->SetDrawable(this->SmallDrawable[3]);
            break;
            case Action::SmallTOBig:
                this->SetDrawable(this->SmallDrawable[4]);
            break;
            case Action::Stop:
                this->SetDrawable(this->SmallDrawable[5]);
                break;
            default:
                break;
        }
    }
    else if(Type == Big) {
        switch(act) {
            case Action::Stand:
                this->SetDrawable(this->BigDrawable[0]);
            break;
            case Action::Run:
                this->SetDrawable(this->BigDrawable[1]);
            break;
            case Action::Jump:
                this->SetDrawable(this->BigDrawable[2]);
            break;
            case Action::BigToSmall:
                this->SetDrawable(this->BigDrawable[3]);
                break;
            case Action::BigToFire:
                this->SetDrawable(this->BigDrawable[4]);
            break;
            case Action::Down:
                this->SetDrawable(this->BigDrawable[5]);
            break;
            case Action::Stop:
                this->SetDrawable(this->BigDrawable[6]);
            break;
            default:
                break;
        }
    }
}

void Mario::Hurt() {
    if(this->Type == Small) {
        this->SetZIndex(2);
        this->SetWCollision(false);
        this->UpDateCurrentState(Die);
        this->SetGravity(-2.0f);
        this->SetCanMove(false);
    }
    else if(this->Type == Big) {
        this->UpDateCurrentState(BigToSmall);
        this->SetHurting(true,Util::Time::GetElapsedTimeMs());
        this->CanMove = false;
    }
    else if(this->Type == Fire) {
        this->SetType(Big);
    }
}
void Mario::RightMove() {
    if (GetAcceleration()<=4.0f && GetAcceleration()>=0.0f) {
        SetAcceleration(GetAcceleration()+0.1f);
        if (GetAcceleration()>4.0) {
            SetAcceleration(4.0);
        }
        this->SetSize({1.35,1.2});
        this->UpDateCurrentState(Run);
        CurrentState = Run;
    }else if (GetAcceleration()<0) {
        SetAcceleration(GetAcceleration()+0.2f);
        this->UpDateCurrentState(Stop);
        CurrentState = Stop;
        this->SetSize({1.35,1.2});
    }
    this->SetPosition({this->GetPosition().x + GetAcceleration(),this->GetPosition().y});

}
void Mario::LeftMove() {
        if (GetAcceleration()>=-4.0f && GetAcceleration()<=0.0f) {
            SetAcceleration(GetAcceleration()-0.1f);
            if (GetAcceleration()<-4.0) {
                SetAcceleration(-4.0);
            }
            this->SetSize({-1.35,1.2});
            this->UpDateCurrentState(Run);
            CurrentState = Run;
        }
        else {
            SetAcceleration(GetAcceleration()-0.2f);
            this->UpDateCurrentState(Stop);
            CurrentState = Stop;
            this->SetSize({-1.35,1.2});
        }
    this->SetPosition({this->GetPosition().x + GetAcceleration(),this->GetPosition().y});

}
void Mario::Jump() {
    if(!this->GetFalling()) {
        this->SetPosition({this->GetPosition().x,this->GetPosition().y + 4});
        this->SetGravity(-8.0f);
    }
}

void Mario::Brakes() {

    if(
    (!Util::Input::IsKeyPressed(Util::Keycode::A) && !Util::Input::IsKeyPressed(Util::Keycode::D)) || ((Util::Input::IsKeyPressed(Util::Keycode::A) ||
    Util::Input::IsKeyPressed(Util::Keycode::D)) && (Util::Input::IsKeyPressed(Util::Keycode::S)) && this->GetType() == Big)  )  {
        if (GetAcceleration()>=0.07f ) {
            SetAcceleration(GetAcceleration()-0.07f);
            this->SetPosition({this->GetPosition().x + GetAcceleration(),this->GetPosition().y});
        }else if (GetAcceleration()<=-0.02f) {
            SetAcceleration(GetAcceleration()+0.07f);
            this->SetPosition({this->GetPosition().x + GetAcceleration(),this->GetPosition().y});
        }
        else{SetAcceleration(0);}


    }
}