//
// Created by Benson on 2025/4/18.
//

#ifndef ITEM_MUSHROOM_HPP
#define ITEM_MUSHROOM_HPP
#include "Item.hpp"
class Item_Mushroom : public Item{
    public:
        explicit Item_Mushroom(const glm::vec2 position) : Item(,position){};
        void Action() override {

        };
};
#endif //ITEM_MUSHROOM_HPP
