//
// Created by benson on 2025/4/29.
//

#ifndef STAR_ITEM_HPP
#define STAR_ITEM_HPP
#include "Object/ItemObject.hpp"
class Star_Item final : public ItemObject{
    public:
        explicit Star_Item(const glm::vec2 &position);
        void Action() override;
        void ChangeMarioState(std::shared_ptr<Mario>& mario) override;
};
#endif //STAR_ITEM_HPP
