//
// Created by benson on 2025/5/27.
//

#ifndef KOOPERFIREBALL_HPP
#define KOOPERFIREBALL_HPP
#include "Object/AnimationObject.hpp"
#include "Mario/Mario.hpp"
class KooperFireBall : public AnimationObject {
    public:
        explicit KooperFireBall(const std::shared_ptr<Mario>& mario,const glm::vec2 Pos);
        void Action();
    private:
        std::shared_ptr<Mario> mario;

};
#endif //KOOPERFIREBALL_HPP
