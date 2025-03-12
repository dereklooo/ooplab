//
// Created by Benson on 2025/3/9.
//

#ifndef m_MARIO_HPP
#define m_MARIO_HPP
#include "AnimationObject.hpp"
enum Action{
    Run,
    Down,
    Jump,
    BigToSmall,
    Stop,
    Swim,
    Stand
 };
class m_mariO final : public AnimationObject {
      public:
          m_mariO() : AnimationObject(1,RESOURCE_DIR"/image/character/mario/big/StandAndDown/big_stand"){};

          void SetCurrentState(Action state);

          Action GetCurrentState();

          std::shared_ptr<AnimationObject> GetCurrentAnimation();

      private:
        std::shared_ptr<AnimationObject> Run = std::make_shared<AnimationObject>(3,RESOURCE_DIR"/image/character/mario/big/run/big_run");
        std::shared_ptr<AnimationObject> Jump = std::make_shared<AnimationObject>(3,RESOURCE_DIR"/image/character/mario/big/jump/big_jump");
        std::shared_ptr<AnimationObject> BigToSmall = std::make_shared<AnimationObject>(3,RESOURCE_DIR"/image/character/mario/big/BigToSmall/big_to_small");
        std::shared_ptr<AnimationObject> Stop = std::make_shared<AnimationObject>(2,RESOURCE_DIR"/image/character/mario/big/stop/big_stop");
        std::shared_ptr<AnimationObject> Swim = std::make_shared<AnimationObject>(5,RESOURCE_DIR"/image/character/mario/big/swim/big_swim");
        std::shared_ptr<AnimationObject> Stand = std::make_shared<AnimationObject>(1,RESOURCE_DIR"/image/character/mario/big/StandAndDown/big_stand");
        std::shared_ptr<AnimationObject> Down = std::make_shared<AnimationObject>(1,RESOURCE_DIR"/image/character/mario/big/StandAndDown/big_down");

        Action CurrentState = Action::Stand;


};
#endif //m_MARIO_HPP
