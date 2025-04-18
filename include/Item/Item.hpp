//
// Created by Benson on 2025/4/18.
//

#ifndef ITEM_HPP
#define ITEM_HPP
#include "Object/StillObject.hpp"
class Item : public StillObject {
    public:
        Item(const std::string &ImagePath, const glm::vec2 position) : StillObject(ImagePath) {
            this->SetPosition(position);
        };
        virtual void Action() = 0;
};
#endif //ITEM_HPP
