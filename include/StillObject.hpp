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
private:
    std::string ImagePath;
};


#endif //STILLOBJECT_HPP
