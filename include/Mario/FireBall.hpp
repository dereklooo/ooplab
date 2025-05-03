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

        void Explode();

        void SetState(FireBallState state);

        void SetWay(Way way);

        Way GetWay() const;

        FireBallState GetState() const;

    private:
        FireBallState state = FireBallState::Roll;
        Way way = Way::Right;
        size_t number;

};
#endif //FIREBALL_HPP
