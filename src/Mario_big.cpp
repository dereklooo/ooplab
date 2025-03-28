//
// Created by Benson on 2025/3/28.
//
#include "Mario/Mario_big.hpp"
Mario_big::Mario_big() : Mario(){
    this->BigDrawable.push_back(this->GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/stand/stand",100,100)); // stand
    this->BigDrawable.push_back(this->GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/run/big_run",400,100)); //run
    this->BigDrawable.push_back(this->GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/jump/small_jump",100,100)); //jump
    this->BigDrawable.push_back(this->GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/BigToSmall/big_to_small",800,200)); // BigtoSmall
    this->BigDrawable.push_back(this->GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/Down/big_down",800,200)); //down
    this->BigDrawable.push_back(this->GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/big/stop/big_stop",800,200)); // stop
}

void Mario_big::Hurt() {

}
void Mario_big::SetCurrentState(int num) {
    switch(num) {
        case 0:
            CurrentState=0;
        break;
        case 1:
            CurrentState=1;
        break;
        case 2:
            CurrentState=3;
        break;
        case 3:
            CurrentState=3;
        break;
        case 4:
            CurrentState=4;
        break;
        case 5:
            CurrentState=5;
        break;
    }

}
void Mario_big::update(std::shared_ptr<Mario> &m_MariO) {
    if (Util::Input::IsKeyPressed(Util::Keycode::D)){
        m_MariO->SetPosition({m_MariO->GetPosition().x + 4,m_MariO->GetPosition().y});
        m_MariO->SetCurrentState(Action::Run);
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
        if(m_MariO->GetPosition().x - 1 <= -620) {
            m_MariO->SetPosition({-620,m_MariO->GetPosition().y});
        }
        m_MariO->SetPosition({m_MariO->GetPosition().x - 4,m_MariO->GetPosition().y});
        m_MariO->SetSize({-1,1});
        m_MariO->SetCurrentState(Action::Run);
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::S)) {
        m_MariO->SetPosition({m_MariO->GetPosition().x,m_MariO->GetPosition().y - 4});
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::W)) {
        m_MariO->SetCurrentState(Action::Jump);
        m_MariO->SetPosition({m_MariO->GetPosition().x,m_MariO->GetPosition().y + 4});
    }


    if(!Util::Input::IsKeyPressed(Util::Keycode::S) &&
        !Util::Input::IsKeyPressed(Util::Keycode::W) &&
        !Util::Input::IsKeyPressed(Util::Keycode::A) &&
        !Util::Input::IsKeyPressed(Util::Keycode::D)) {
        m_MariO->SetCurrentState(Action::Stand);
        }
}