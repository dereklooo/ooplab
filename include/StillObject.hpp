//
// Created by Benson on 2025/3/9.
//

#ifndef STILLOBJECT_HPP
#define STILLOBJECT_HPP

#include <string>
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class StillObject : public Util::GameObject {
public:
    StillObject(std::string ImagePath) : ImagePath(ImagePath) {m_Drawable = std::make_shared<Util::Image>(ImagePath);};

    void SetPosition(const glm::vec2 &position) {m_Transform.translation = position;}

    void SetSize(glm::vec2 size) {m_Transform.scale = size;}

    glm::vec2 GetPosition() {return m_Transform.translation;}

    std::shared_ptr<Core::Drawable> GetDrawable() {return m_Drawable;}

    void SetImagePath(std::string){this->ImagePath = ImagePath;}

    bool collition(const GameObject& other) {
        if(other.GetTransform().translation.x + (other.GetScaledSize().x / 2) >= this->GetPosition().x &&
            other.GetTransform().translation.x - (other.GetScaledSize().x / 2) <= this->GetPosition().x &&
            other.GetTransform().translation.y - (other.GetScaledSize().y / 2) <= this->GetPosition().x &&
            other.GetTransform().translation.y + (other.GetScaledSize().y / 2) >= this->GetPosition().x) {
            return true;
            }
        return false;
    }
protected:
    std::string ImagePath;
};


#endif //STILLOBJECT_HPP
