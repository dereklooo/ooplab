//
// Created by Benson on 2025/4/27.
//

#ifndef GRAVITYOBJECT_HPP
#define GRAVITYOBJECT_HPP
class GravityObject final{
    public:
        GravityObject(){};
        void SetGravity(const float gravity) {
            this->gravity = gravity;
        };
        float GetGravity() const {
            return gravity;
        }
        bool GetFalling() const {
            return Falling;
        }
        float GetFallingTime() const {
            return FallingTime;
        }
        void SetFallingTime(const float &FallingTime) {
            this->FallingTime = FallingTime;
        }
        void SetFalling(const bool f) {
            this->Falling = f;
        }


    private:
        float gravity = 9.8;
        bool Falling = false;
        float FallingTime = 0;

};
#endif //GRAVITYOBJECT_HPP


//測試用