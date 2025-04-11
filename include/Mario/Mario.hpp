//
// Created by Benson on 2025/3/28.
//

#ifndef m_MARIO_HPP
#define m_MARIO_HPP
#include "Object/AnimationObject.hpp"
#include "Object/StillObject.hpp"
#include "Util/Time.hpp"
#include "Util/Input.hpp"
enum Type {
    Small,
    Big,
    Fire
};

class Mario : public AnimationObject{
    public:
        Mario():AnimationObject(1,RESOURCE_DIR"/image/character/mario/small/stand/small_stand") {
            CurrentState=2;
        };

        void virtual SetCurrentState(int num) = 0;

        void virtual Hurt() = 0;

        void virtual update()=0;
    void SetAcceleration(const float num) {
        this->horizontalAcceleration = num;
    }
    float GetAcceleration() const {
        return horizontalAcceleration;
    }

        Type GetType() const {
            return Type;
        }
    protected:
        void jump ();
        void leftMove ();
        void rightMove ();
        void brakes();
        std::vector<std::shared_ptr<Core::Drawable>> BigDrawable;
        int CurrentState;
        glm::vec2 speed = {0,0};
        Type Type;
        float horizontalAcceleration = 0.0f;
};
#endif //m_MARIO_HPP
