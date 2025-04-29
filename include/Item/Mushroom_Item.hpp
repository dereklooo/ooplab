//
// Created by Benson on 2025/4/19.
//

#ifndef MUSHROOM_ITEM_HPP
#define MUSHROOM_ITEM_HPP
#include "Object/ItemObject.hpp"
class Mushroom_Item final : public ItemObject {
public:
    explicit Mushroom_Item(const glm::vec2 &position);
    void Action() override;
    void ChangeMarioState(std::shared_ptr<Mario>& mario) override;
};
#endif //MUSHROOM_ITEM_HPP
