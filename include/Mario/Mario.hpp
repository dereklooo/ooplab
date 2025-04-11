//
// Created by Benson on 2025/3/28.
//

#ifndef m_MARIO_HPP
#define m_MARIO_HPP
#include "Object/AnimationObject.hpp"
#include "Object/StillObject.hpp"
#include "Util/Time.hpp"
enum Type {
    Small,
    Big,
    Fire
};
#include "Util/Input.hpp"
class Mario : public AnimationObject{
    public:
        Mario():AnimationObject(1,RESOURCE_DIR"/image/character/mario/small/stand/small_stand") {
            CurrentState=2;
        };

        void virtual SetCurrentState(int num) = 0;

        void virtual Hurt() = 0;

        void virtual update(std::shared_ptr<Mario> &m_MariO)=0;


        Type GetType() const {
            return Type;
        }
    protected:
        void jump ();
        std::vector<std::shared_ptr<Core::Drawable>> BigDrawable;
        int CurrentState;
        glm::vec2 speed = {0,0};
        Type Type;
};
#endif //m_MARIO_HPP
