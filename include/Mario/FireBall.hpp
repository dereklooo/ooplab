//
// Created by benson on 2025/5/2.
//

#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "Object/AnimationObject.hpp"
class FireBall final: public AnimationObject {
    public:
        FireBall();
        void Rolling();
        void Exploding();
    private:

};
#endif //FIREBALL_HPP
