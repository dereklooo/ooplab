//
// Created by Benson on 2025/3/9.
//

#ifndef STILLOBJECT_HPP
#define STILLOBJECT_HPP

#include <string>
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class StillCharacter : public Util::GameObject {
public:
    StillCharacter(std::string ImagePath) : ImagePath(ImagePath) {m_Drawable = std::make_shared<Util::Image>(ImagePath);};

private:
    std::string ImagePath;
};


#endif //STILLOBJECT_HPP
