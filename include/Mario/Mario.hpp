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
    SmallToBig,
    BigToFire,
    BigToSmall,
    Shoot,
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
        void AddScore(const int adder) {
            Score += adder;
        }
        int GetScore() const{
            return Score;
        }
        void AddCoin(const int adder) {
            Coin += adder;
        }
        int GetCoin() const{
            return Coin;
        }
        bool GetShooting() const {
            return Shooting;
        }
        void SetShooting(const bool Shooting){
            this->Shooting = Shooting;
        }
        void SetAnimation(const bool B) {
            this->Animating = B;
        }
        bool GetAnimating() const {
            return Animating;
        }
        void SetAnimationWay(const Way way) {
            this->AnimationWay = way;
        }
        Way GetAnimationWay() const {
            return AnimationWay;
        }
        void SetInPipe(const bool B) {
            this->InPipe = B;
        }
        bool GetInPipe() const {
            return InPipe;
        }
        void SetNextPosition(glm::vec2 Next) {
            this->NextPos = Next;
        }
        glm::vec2 GetNextPosition() const {
            return NextPos;
        }
        void Hurt() ;

        void Jump ();

        void LeftMove ();

        void RightMove ();

        void Brakes();

        void Shoot();

    bool GetTouchFlagFlag(){return TouchFlagFlag;}
    void SetTouchFlagFlag(bool flag) {TouchFlagFlag=flag;}
    void SetMarioGoDoorFlag(bool flag) {MarioGoDoorFlag=flag;}
    bool GetMarioGoDoorFlag() {return MarioGoDoorFlag;}
    void SetNextLevelFlag(bool flag) {NextLevelFlag=flag;}
    bool GetNextLevelFlag() {return NextLevelFlag;}

    protected:
        struct Star_ {bool Staring = false;float StartShiningTime = 0.0f;};
        struct Hurt_ {bool Hurting = false;float StartHurtingTIme = 0.0f;};
        Star_ star;
        Hurt_ hurt;
        bool CanMove = true;
        bool Shooting = false;
        bool Animating = false;
        bool InPipe = false;
        bool TouchFlagFlag=false;
        bool MarioGoDoorFlag=false;
        bool NextLevelFlag=false;
        int Score = 0;
        int Coin = 0;
        glm::vec2 NextPos;
        Way AnimationWay;
        std::vector<std::shared_ptr<Core::Drawable>> BigDrawable;
        std::vector<std::shared_ptr<Core::Drawable>> SmallDrawable;
        std::vector<std::shared_ptr<Core::Drawable>> FireDrawable;
        Action CurrentState;
        Type Type;
        float horizontalAcceleration = 0.0f;
};
#endif //m_MARIO_HPP
