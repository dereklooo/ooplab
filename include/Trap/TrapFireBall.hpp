//
// Created by benson on 2025/5/26.
//

#ifndef TRAPFIREBALL_HPP
#define TRAPFIREBALL_HPP
#include "Object/AnimationObject.hpp"
class TrapFireBall final : public AnimationObject {
    public:
        explicit TrapFireBall(glm::vec2 center,float Radius);
        void Rotate();
        void SetCenter(const glm::vec2 Center){this->Center = Center;};
        glm::vec2 GetCenter() const {return Center;};
    private:
        glm::vec2 Center;
        float Radius;
        double AngleRad;
        double AngleDegrees = 0.0f;
};
#endif //TRAPFIREBALL_HPP
