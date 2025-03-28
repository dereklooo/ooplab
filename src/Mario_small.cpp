//
// Created by Benson on 2025/3/28.
//
#include "Mario/Mario_small.hpp"

Mario_small::Mario_small() : Mario(){
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/stand/small_stand",400,100)); // stand
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/small/run/small_run",400,100)); //run
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/jump/small_jump",400,100)); // jump
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/die/small_die",400,100)); // die
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/SmalltoBig/SmalltoBig",800,200)); //smalltobig
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(1,RESOURCE_DIR"/image/character/mario/small/stop/small_stop",400,100)); //stop

}
void Mario_small::Hurt() {

}
void Mario_small::SetCurrentState(int num) {
    switch(num) {
        case 0:
            CurrentState=0;
            this->SetDrawable(this->SmallDrawable[1]);
            break;
        case 1:
            CurrentState=1;
            this->SetDrawable(this->SmallDrawable[2]);
        break;
        case 2:
            CurrentState=2;
            this->SetDrawable(this->SmallDrawable[0]);
            break;
        case 3:
            CurrentState=3;
        this->SetDrawable(this->SmallDrawable[5]);
        break;
        case 4:
            CurrentState=4;
        this->SetDrawable(this->SmallDrawable[4]);
        break;
        case 5:
            CurrentState=5;
        this->SetDrawable(this->SmallDrawable[3]);
        break;
    }

}
void Mario_small::update(std::shared_ptr<Mario> &m_MariO) {
    if (Util::Input::IsKeyPressed(Util::Keycode::D)){
        m_MariO->SetPosition({m_MariO->GetPosition().x + 1,m_MariO->GetPosition().y});
        m_MariO->SetCurrentState(Action::Run);
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
        if(m_MariO->GetPosition().x - 1 <= -620) {
            m_MariO->SetPosition({-620,m_MariO->GetPosition().y});
        }
        else {
            m_MariO->SetPosition({m_MariO->GetPosition().x - 4,m_MariO->GetPosition().y});
        }

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