//
// Created by Benson on 2025/4/19.
//

#ifndef MUSHROOM_ITEM_HPP
#define MUSHROOM_ITEM_HPP
#include "Object/ItemObject.hpp"
class Mushroom_Item final : public ItemObject {
public:
    explicit Mushroom_Item(const glm::vec2 &position) : ItemObject(position,RESOURCE_DIR"/image/character/Item/Mushroom.png") {

    };
    void Action() override {
        switch(state) {
            case ItemState::Hidden:

                break;
            case ItemState::Collected:

                break;
            case ItemState::Walking:

                break;
            case ItemState::PoppingUp:

                break;

        }
    }
};
#endif //MUSHROOM_ITEM_HPP
