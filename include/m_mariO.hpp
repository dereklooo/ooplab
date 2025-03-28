//
// Created by Benson on 2025/3/9.
//

#ifndef m_MARIO_HPP
#define m_MARIO_HPP
#include "AnimationObject.hpp"
#include "StillObject.hpp"
enum Size{Big ,Small};
enum Action{
    Run,
    Down,
    Jump,
    BigToSmall,
    Stop,
    Swim,
    Stand,
    Die
 };
class m_mariO final : public AnimationObject {
      public:
          m_mariO();

          void SetCurrentState(Action state);

          Action GetCurrentState();

          std::shared_ptr<AnimationObject> GetCurrentAnimation();

          void Hurt() {
              if(size == Big) {
                  this->SetCurrentState(Action::BigToSmall);
                  size = Small;
              }
              else {
                  this->SetCurrentState(Action::Die);
              }
          }
        bool Collision(const std::shared_ptr<GameObject> &other) {
            if (
                other->GetTransform().translation.x + (other->GetScaledSize().x / 2) >= this->GetPosition().x - (this->GetScaledSize().x / 2) &&
                other->GetTransform().translation.x - (other->GetScaledSize().x / 2) <= this->GetPosition().x + (this->GetScaledSize().x / 2) &&
                other->GetTransform().translation.y + (other->GetScaledSize().y / 2) >= this->GetPosition().y - (this->GetScaledSize().y / 2) &&
                other->GetTransform().translation.y - (other->GetScaledSize().y / 2) <= this->GetPosition().y + (this->GetScaledSize().y / 2)
            ) {
                return true;
            }
            return false;
        }
      private:
        std::vector<std::shared_ptr<Core::Drawable>> BigDrawable;
        std::vector<std::shared_ptr<Core::Drawable>> SmallDrawable;


        Action CurrentState = Action::Stand;
        Size size = Big;

};
#endif //m_MARIO_HPP
