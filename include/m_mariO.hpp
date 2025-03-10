//
// Created by Benson on 2025/3/9.
//

#ifndef m_MARIO_HPP
#define m_MARIO_HPP
#include "AnimationObject.hpp"
enum Action{
    Run,
    Jump,
    BigToSmall,
    Stop,
    Swim,
    Stand
 };
class m_mariO : public AnimationObject {
      public:

          void SetCurrentState(Action state);

          Action GetCurrentState();

          std::shared_ptr<Core::Drawable> GetCurrentAnimation();

      private:
        std::shared_ptr<Util::Animation> Run;
        std::shared_ptr<Util::Animation> Jump;
        std::shared_ptr<Util::Animation> BigToSmall;
        std::shared_ptr<Util::Animation> Stop;
        std::shared_ptr<Util::Animation> Swim;
        std::shared_ptr<Util::Image> Stand;
        std::shared_ptr<Util::Image> down;

        Action CurrentState = Action::Stand;


};
#endif //m_MARIO_HPP
