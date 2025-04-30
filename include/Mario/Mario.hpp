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
    Star,
};

class Mario final : public AnimationObject{
    public:
        Mario();

        void UpDateCurrentState(Action act);

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

        Action GetCurrentState() const {
            return CurrentState;
        }

        void SetCurrentState(const Action action) {
            this->CurrentState = action;
        }
        bool GetStaring() const {
            return star.Staring;
        }
        void SetStaring(const bool B_, const float StartShining) {
            this->star.Staring = B_;
            this->star.StartShiningTime = StartShining;

        }
        float GetStartShiningTime() const{
            return star.StartShiningTime;
        }
        void SetCanMove(const bool B) {
            this->CanMove = B;
        }
        bool GetCanMove() const {
            return CanMove;
        }
        void SetHurting(const bool B, const float StartTime) {
            hurt.Hurting = B;
            hurt.StartHurtingTIme = StartTime;
        }
        bool GetHurting() const {
            return hurt.Hurting;
        }
        float GetHurtingTime() const {
            return hurt.StartHurtingTIme;
        }

        void Hurt() ;

        void Jump ();

        void LeftMove ();

        void RightMove ();

        void Brakes();
    protected:
        struct Star_ {bool Staring = false;float StartShiningTime = 0.0f;};
        struct Hurt_ {bool Hurting = false;float StartHurtingTIme = 0.0f;};
        Star_ star;
        Hurt_ hurt;
        bool CanMove = true;
        std::vector<std::shared_ptr<Core::Drawable>> BigDrawable;
        std::vector<std::shared_ptr<Core::Drawable>> SmallDrawable;
        Action CurrentState;
        glm::vec2 speed = {0,0};
        Type Type;
        float horizontalAcceleration = 0.0f;
};
#endif //m_MARIO_HPP
