//
// Created by benson on 2025/5/2.
//

#ifndef FIREFLOWER_ITEM_HPP
#define FIREFLOWER_ITEM_HPP
//
// Created by benson on 2025/5/2.
//
#include "Object/ItemObject.hpp"
class FireFlower final : public ItemObject {
    public:
        explicit FireFlower(const glm::vec2 &position);
        void Action() override;
        void ChangeMarioState(std::shared_ptr<Mario>& mario) override;
};

#endif //FIREFLOWER_ITEM_HPP
