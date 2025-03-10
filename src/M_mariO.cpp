//
// Created by benson on 2025/3/10.
//
#include "m_mariO.hpp"

        void m_mariO::SetCurrentState(Action state){
            CurrentState = state;
            m_Drawable = GetCurrentAnimation();
        };

        Action m_mariO::GetCurrentState(){
            return CurrentState;
        };

        std::shared_ptr<Core::Drawable> GetCurrentAnimation(){
            switch(this->GetCurrentState()){
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
            }

