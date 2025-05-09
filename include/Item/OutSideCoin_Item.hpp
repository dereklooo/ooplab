//
// Created by Benson on 2025/5/8.
//

#ifndef OUTSIDECOIN_ITEM_HPP
#define OUTSIDECOIN_ITEM_HPP
#include "Object/ItemObject.hpp"
class OutSideCoin_Item : public ItemObject {
    public:
        explicit OutSideCoin_Item(const glm::vec2 &position);
        void Action() override;
        void ChangeMarioState(std::shared_ptr<Mario> &mario) override;
};
#endif //OUTSIDECOIN_ITEM_HPP
