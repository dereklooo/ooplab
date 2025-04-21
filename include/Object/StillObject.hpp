//
// Created by Benson on 2025/3/9.
//

#ifndef STILLOBJECT_HPP
#define STILLOBJECT_HPP

#include <string>

#include "Object.hpp"

#include "Util/Image.hpp"


class StillObject : public Object {
public:
    StillObject(std::string ImagePath) : ImagePath(ImagePath) {m_Drawable = std::make_shared<Util::Image>(ImagePath);};

    void SetImagePath(std::string){this->ImagePath = ImagePath;}

protected:
    std::string ImagePath;
};


#endif //STILLOBJECT_HPP
