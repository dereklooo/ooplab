//
// Created by Benson on 2025/4/19.
//

#ifndef COIN_ITEM_HPP
#define COIN_ITEM_HPP
#include <iostream>
#include <ostream>

#include "Object/ItemObject.hpp"
class Coin_Item : public ItemObject {
    public:
        explicit Coin_Item(const glm::vec2 &position);
        void Action() override;
        void ChangeMarioState(std::shared_ptr<Mario> &mario) override;
};
#endif //COIN_ITEM_HPP
