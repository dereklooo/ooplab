//
// Created by benson on 2025/3/10.
//
#include "m_mariO.hpp"
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
                default:
                    return nullptr;
                    break;
            }
        }
        bool m_mariO::Ifcolide(std::shared_ptr<GameObject> Object) {
            if (Object->GetTransform().translation.x <= this->GetPosition().x + this->GetScaledSize().x / 2 &&
                Object->GetTransform().translation.x >= this->GetPosition().x - this->GetScaledSize().x / 2 &&
                Object->GetTransform().translation.y <= this->GetPosition().y + this->GetScaledSize().y / 2 &&
                Object->GetTransform().translation.y >= this->GetPosition().x - this->GetScaledSize().x / 2) {
                return true;
            }
            return false;
        }
