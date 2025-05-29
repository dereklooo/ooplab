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
        bool GetVisible() {
            return m_Visible;
        }

    // 判斷某個點是否在當前物件的範圍內
    bool Collision(const glm::vec2 &point) const {
            float halfWidth  = std::abs(this->GetScaledSize().x / 2.0f);
            float halfHeight = std::abs(this->GetScaledSize().y / 2.0f);
            glm::vec2 pos = this->GetPosition();

            return point.x >= pos.x - halfWidth && point.x <= pos.x + halfWidth &&
                   point.y >= pos.y - halfHeight && point.y <= pos.y + halfHeight;
        }

    // 向下碰撞
    bool DownCollision(const std::shared_ptr<Object> &other) const {
            float x = this->GetPosition().x;
            float y = this->GetPosition().y - std::abs(this->GetScaledSize().y / 2.0f) - 3;

            glm::vec2 p1 = {x + 15, y};
            glm::vec2 p2 = {x - 15, y};

            return other->Collision(p1) || other->Collision(p2);
        }

    // 向上碰撞
    bool UpCollision(const std::shared_ptr<Object> &other) const {
            float x = this->GetPosition().x;
            float y = this->GetPosition().y + std::abs(this->GetScaledSize().y / 2.0f) + 10;

            glm::vec2 p1 = {x + 10, y};
            glm::vec2 p2 = {x - 10, y};

            return other->Collision(p1) || other->Collision(p2);
        }

    // 向左碰撞
    bool LeftCollision(const std::shared_ptr<Object> &other) const {
            float x = this->GetPosition().x - std::abs(this->GetScaledSize().x / 2.0f) - 10;
            float halfHeight = std::abs(this->GetScaledSize().y / 2.0f);
            float y = this->GetPosition().y;

            glm::vec2 top = {x, y + halfHeight - 10};
            glm::vec2 mid = {x, y - halfHeight + 20};

            return other->Collision(top) || other->Collision(mid);
        }

    // 向右碰撞（上、中、下三點檢測）
    bool RightCollision(const std::shared_ptr<Object> &other) const {
            float x = this->GetPosition().x + std::abs(this->GetScaledSize().x / 2.0f) + 6;
            float halfHeight = std::abs(this->GetScaledSize().y / 2.0f);
            float y = this->GetPosition().y;

            glm::vec2 top = {x, y + halfHeight - 10};
            glm::vec2 mid = {x, y - halfHeight + 20};

            return other->Collision(top) || other->Collision(mid);
        }

        glm::vec2  GetSize() const {
            return m_Transform.scale;
        }
        bool GetWCollision() const {
            return WantCollision;
        }
        void SetWCollision(bool W) {
            this->WantCollision = W;
        }
    private:
        float GravityNum = 9.0f;
        float FallingTime = 0.0f;
        bool Falling = false;
        bool WantCollision = true;
};
#endif //OBJECT_HPP
