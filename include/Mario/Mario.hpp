//
// Created by Benson on 2025/3/28.
//

#ifndef m_MARIO_HPP
#define m_MARIO_HPP
#include "Object/AnimationObject.hpp"
#include "Object/StillObject.hpp"
class Mario : public AnimationObject{
    public:
        Mario();

        void virtual SetCurrentState(int num) = 0;

        void virtual Hurt() = 0;


        bool Collision(const std::shared_ptr<GameObject> &other) {
            if (
                other->GetTransform().translation.x + (other->GetScaledSize().x / 2) >= this->GetTransform().translation.x - (this->GetScaledSize().x / 2) &&
                other->GetTransform().translation.x - (other->GetScaledSize().x / 2) <= this->GetTransform().translation.x + (this->GetScaledSize().x / 2) &&
                other->GetTransform().translation.y + (other->GetScaledSize().y / 2) >= this->GetTransform().translation.y - (this->GetScaledSize().y / 2) &&
                other->GetTransform().translation.y - (other->GetScaledSize().y / 2) <= this->GetTransform().translation.y + (this->GetScaledSize().y / 2)
            ) {
                return true;
            }
            return false;
        }
    protected:
        std::vector<std::shared_ptr<Core::Drawable>> BigDrawable;
        int CurrentState;
};
#endif //m_MARIO_HPP
