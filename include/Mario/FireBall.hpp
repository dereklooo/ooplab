//
// Created by benson on 2025/5/2.
//

#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "Object/AnimationObject.hpp"
#include "Util/Time.hpp"
enum FireBallState {Exploding,Rolling};
class FireBall final: public AnimationObject {
    public:
        explicit FireBall(glm::vec2 position);

        void Rolling();

        void Explode();

        void SetState(FireBallState state);

        FireBallState GetState() const;

    private:
        FireBallState state = FireBallState::Rolling;

};
#endif //FIREBALL_HPP
