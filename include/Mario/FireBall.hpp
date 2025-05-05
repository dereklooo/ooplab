//
// Created by benson on 2025/5/2.
//

#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "Object/AnimationObject.hpp"
#include "Util/Time.hpp"
enum FireBallState {Explode,Roll,End};
class FireBall final: public AnimationObject {
    public:
        explicit FireBall(glm::vec2 position);

        void Rolling();

        void Explode(float Time);

        void SetState(FireBallState state);

        void SetWay(Way way);

        Way GetWay() const;

        FireBallState GetState() const;

        float GetStartExplodeTime() const;
    private:
        std::shared_ptr<Util::Animation> rolling = AnimationObject::GenerateAnimation(4,RESOURCE_DIR"/image/character/mario/fire/fireball/Rollingfireball",100,20);
        std::shared_ptr<Util::Animation> explode = AnimationObject::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/fire/fireball/explode",200,100);
        FireBallState state = FireBallState::Roll;
        Way way = Way::Right;
        size_t number;
        float StartExplodeTime;
};
#endif //FIREBALL_HPP
