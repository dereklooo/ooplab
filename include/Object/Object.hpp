//
// Created by benson on 2025/4/3.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "Util/GameObject.hpp"
enum Way {Right ,Left};
class Object : public Util::GameObject{
    public:
        Object() = default;
        glm::vec2 GetPosition() const {return m_Transform.translation;}
        void SetPosition(const glm::vec2 &position) {m_Transform.translation = position;}
        void SetSize(const glm::vec2 size) {m_Transform.scale = size;}
        std::shared_ptr<Core::Drawable> GetDrawable() {return m_Drawable;}


        void SetGravity(const float num) {
            this->GravityNum = num;
        }
        float GetGravity() const {
            return GravityNum;
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


        bool Collision(const glm::vec2 &other) const {
                if (
                    other.x <= this->GetPosition().x + abs(this->GetScaledSize().x / 2)&&
                    other.x >= this->GetPosition().x - abs(this->GetScaledSize().x / 2)&&
                    other.y <= this->GetPosition().y + abs(this->GetScaledSize().y / 2)&&
                    other.y >= this->GetPosition().y - abs(this->GetScaledSize().y / 2)
                ) {
                    return true;
                }
                return false;
            }
        bool DownCollision(const std::shared_ptr<Object> &other) const {
            glm::vec2 TempPos = {this->GetPosition().x, this->GetPosition().y - abs(this->GetScaledSize().y / 2) - 2};
            if(other->Collision(TempPos)){
                return true;
            }
            return false;
        }
        bool LeftCollision(const std::shared_ptr<Object> &other) const{
            glm::vec2 TempPos = {this->GetPosition().x - abs(this->GetScaledSize().x / 2) - 4, this->GetPosition().y};
            if(other->Collision(TempPos)) {
                return true;
            }
            return false;
        }
        bool RightCollision(const std::shared_ptr<Object> &other) const{
            glm::vec2 TempPos = {this->GetPosition().x + abs(this->GetScaledSize().x / 2) + 4, this->GetPosition().y};
            if(other->Collision(TempPos)) {
                return true;
            }
            return false;
        }
        bool UpCollision(const std::shared_ptr<Object> &other) const{
            glm::vec2 TempPos = {this->GetPosition().x, this->GetPosition().y + abs(this->GetScaledSize().y / 2) + 2};
            if(other->Collision(TempPos)) {
                return true;
            }
            return false;
        }
    private:
        float GravityNum = 9.8f;
        float FallingTime = 0.0f;
        bool Falling = false;

};
#endif //OBJECT_HPP
