//
// Created by Benson on 2025/3/28.
//
#include "Mario/Mario_big.hpp"
Mario_big::Mario_big() : Mario(){
    this->BigDrawable.push_back(this->GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/stand/stand",100,100)); // stand
    this->BigDrawable.push_back(this->GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/run/big_run",200,100)); //run
    this->BigDrawable.push_back(this->GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/jump/small_jump",100,100)); //jump
    this->BigDrawable.push_back(this->GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/BigToSmall/big_to_small",800,200)); // BigtoSmall
    this->BigDrawable.push_back(this->GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/Down/big_down",800,200)); //down
    this->BigDrawable.push_back(this->GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/stop/big_stop",800,200)); // stop
    this->SetSize({1.4,1.4});
    this->Type = Big;
}

void Mario_big::Hurt() {

}
void Mario_big::UpDateCurrentState(int num) {
        switch(num) {
            case 0:

                this->SetDrawable(this->BigDrawable[1]);
            break;
            case 1:

                this->SetDrawable(this->BigDrawable[2]);
            break;
            case 2:

                this->SetDrawable(this->BigDrawable[0]);
            break;
            case 3:

                this->SetDrawable(this->BigDrawable[5]);
            break;
            case 4:

                this->SetDrawable(this->BigDrawable[4]);
            break;
            case 5:

                this->SetDrawable(this->BigDrawable[3]);
            break;
            default:
                break;
        }

}

void Mario_big::update() {
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

    Mario::brakes();
    if (GetAcceleration()==0) {
        CurrentState=2;
        this->UpDateCurrentState(CurrentState);

    }
}