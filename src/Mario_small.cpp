//
// Created by Benson on 2025/3/28.
//
#include "Mario/Mario_small.hpp"
#include "Util/Renderer.hpp"
#include <iostream>
#include "Util/Time.hpp"
Mario_small::Mario_small() : Mario(){
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/stand/small_stand",400,100)); // stand
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/small/run/small_run",90,60)); //run
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/jump/small_jump",400,100)); // jump
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/die/die",400,100)); // die
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/small/SmalltoBig/SmalltoBig",800,200)); //smalltobig
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/stop/small_stop",400,100)); //stop
    this->SetSize({1.4,1.4});
    this->Type = Small;
}
void Mario_small::Hurt() {
    this->UpDateCurrentState(Action::Die);
}
void Mario_small::UpDateCurrentState(const int num) {
    switch(num) {
        case 0:

            this->SetDrawable(this->SmallDrawable[1]);
            break;
        case 1:

            this->SetDrawable(this->SmallDrawable[2]);
        break;
        case 2:

            this->SetDrawable(this->SmallDrawable[0]);
            break;
        case 3:

            this->SetDrawable(this->SmallDrawable[5]);
        break;
        case 4:

            this->SetDrawable(this->SmallDrawable[4]);
        break;
        case 5:

            this->SetDrawable(this->SmallDrawable[3]);
        break;
        default:
        break;
    }

}
void Mario_small::update() {
    if (Util::Input::IsKeyPressed(Util::Keycode::D)){
        rightMove();
        this->UpDateCurrentState(CurrentState);
    }

    else if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
        leftMove();

        this->UpDateCurrentState(CurrentState);
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::S)) {


    }

    if(Util::Input::IsKeyPressed(Util::Keycode::W)) {

        jump();
        CurrentState=1;
        this->UpDateCurrentState(CurrentState);

    }

    if(Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
        std::cout<<this->GetPosition().x<<" "<<this->GetPosition().y << " "<< Util::Time::GetDeltaTime()<<std::endl;
    }

    Mario::brakes();
    if (GetAcceleration()==0) {
        CurrentState=2;
        this->UpDateCurrentState(CurrentState);

    }
}