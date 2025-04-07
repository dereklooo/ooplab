//
// Created by benson on 2025/4/3.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "Util/GameObject.hpp"
class Object : public Util::GameObject{
    public:
        Object() = default;
        glm::vec2 GetPosition() {return m_Transform.translation;}
        void SetPosition(const glm::vec2 &position) {m_Transform.translation = position;}
        void SetSize(glm::vec2 size) {m_Transform.scale = size;}
        std::shared_ptr<Core::Drawable> GetDrawable() {return m_Drawable;}
    private:
};
#endif //OBJECT_HPP
