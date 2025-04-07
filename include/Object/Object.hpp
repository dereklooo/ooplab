//
// Created by benson on 2025/4/3.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "Util/GameObject.hpp"
class Object : public Util::GameObject{
    public:
        Object() = default;
        glm::vec2 GetPosition() const {return m_Transform.translation;}
        void SetPosition(const glm::vec2 &position) {m_Transform.translation = position;}
        void SetSize(glm::vec2 size) {m_Transform.scale = size;}
        std::shared_ptr<Core::Drawable> GetDrawable() {return m_Drawable;}



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
            glm::vec2 TempPos = {this->GetPosition().x, this->GetPosition().y - abs(this->GetScaledSize().y / 2) - 12};
            if(other->Collision(TempPos)) {
                return true;
            }
            return false;
        }
        bool LeftCollision(const std::shared_ptr<Object> &other) const{
            glm::vec2 TempPos = {this->GetPosition().x - abs(this->GetScaledSize().x / 2) - 12, this->GetPosition().y};
            if(other->Collision(TempPos)) {
                return true;
            }
            return false;
        }
        bool RightCollision(const std::shared_ptr<Object> &other) const{
            glm::vec2 TempPos = {this->GetPosition().x + abs(this->GetScaledSize().x / 2) + 12, this->GetPosition().y};
            if(other->Collision(TempPos)) {
                return true;
            }
            return false;
        }
        bool UpCollision(const std::shared_ptr<Object> &other) const{
            glm::vec2 TempPos = {this->GetPosition().x, this->GetPosition().y + abs(this->GetScaledSize().y / 2) + 12};
            if(other->Collision(TempPos)) {
                return true;
            }
            return false;
        }
};
#endif //OBJECT_HPP
