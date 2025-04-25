//
// Created by Benson on 2025/3/28.
//

#ifndef m_MARIO_HPP
#define m_MARIO_HPP
#include "Object/AnimationObject.hpp"
#include "Object/StillObject.hpp"
#include "Util/Time.hpp"
#include "Util/Input.hpp"

enum Action {
    Stand,
    Run,
    Jump,
    Die,
    SmallTOBig,
    BigToFire,
    BigToSmall,
    Stop,
    Down
};
enum Type {
    Small,
    Big,
    Fire,
};

class Mario : public AnimationObject{
    public:
        Mario();

        void UpDateCurrentState(Action act);

        void Hurt() ;

        void update();

        void SetAcceleration(const float num) {
            this->horizontalAcceleration = num;
        }

        float GetAcceleration() const {
            return horizontalAcceleration;
        }

        Type GetType() const {
            return Type;
        }
        void SetType(const Type type) {
            this->Type = type;
        }
        void Jump ();

        void LeftMove ();

        void RightMove ();

        void Brakes();
    protected:

        std::vector<std::shared_ptr<Core::Drawable>> BigDrawable;
        std::vector<std::shared_ptr<Core::Drawable>> SmallDrawable;
        Action CurrentState;
        glm::vec2 speed = {0,0};
        Type Type;
        float horizontalAcceleration = 0.0f;
};
#endif //m_MARIO_HPP
