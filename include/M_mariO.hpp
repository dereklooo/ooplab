//
// Created by Benson on 2025/3/9.
//

#ifndef M_MARIO_HPP
#define M_MARIO_HPP
#include "AnimationObject.hpp"
enum State{
    Run,
    Jump,
    BigToSmall,
    Stop,
    Swim,
    Stand
 };
class M_mariO : public AnimationObject {
      public:

      private:
        std::shared_ptr<Util::Animation> Run;
        std::shared_ptr<Util::Animation> Jump;
        std::shared_ptr<Util::Animation> BigToSmall;
        std::shared_ptr<Util::Animation> Stop;
        std::shared_ptr<Util::Animation> Swim;
        std::shared_ptr<Util::Image> Stand;
        std::shared_ptr<Util::Image> down;

        State state = State::Stand;


};
#endif //M_MARIO_HPP
