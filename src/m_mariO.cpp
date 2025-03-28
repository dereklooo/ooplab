//
// Created by benson on 2025/3/27.
//
#include "m_mariO.hpp"
    m_mariO::m_mariO() : AnimationObject(1,RESOURCE_DIR"/image/character/mario/big/StandAndDown/big_stand") {
        this->BigDrawable.push_back(this->GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/run/big_run",400,100)); //run
        this->BigDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/big/jump/big_jump.png")); //jump
        this->BigDrawable.push_back(this->GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/BigToSmall/big_to_small1",800,200)); // BigtoSmall
        this->BigDrawable.push_back(std::make_shared<Util::Image>("Resources/image/character/mario/big/StandAndDown/big_down1.png")); //down

        this->SmallDrawable.push_back()
    }
    void m_mariO::SetCurrentState(const Action state){
        CurrentState = state;
        this->SetDrawable(GetCurrentAnimation()->GetDrawable());
    };

    Action m_mariO::GetCurrentState(){
        return CurrentState;
    };

    std::shared_ptr<AnimationObject> m_mariO::GetCurrentAnimation(){
        switch(CurrentState){
            case(Action::Run):
                return Run;
            break;
            case (Action::Jump):
                return Jump;
            break;
            case(Action::BigToSmall):
                return BigToSmall;
            break;
            case(Action::Stop):
                return Stop;
            break;
            case(Action::Swim):
                return Swim;
            break;
            case(Action::Stand):
                return Stand;
            break;
            case(Action::Down):
                return Down;
            break;
            case(Action::Die):
                return Die;
            break;
            default:
                return nullptr;
            break;
        }
}