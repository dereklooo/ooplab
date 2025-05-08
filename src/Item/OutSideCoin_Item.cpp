//
// Created by Benson on 2025/5/8.
//
#include "Item/OutSideCoin_Item.hpp"
OutSideCoin_Item::OutSideCoin_Item(const glm::vec2 &position) : ItemObject(position,RESOURCE_DIR"/image/character/Item/Coin.png"){

}
void OutSideCoin_Item::Action() {

}

void OutSideCoin_Item::ChangeMarioState(std::shared_ptr<Mario> &mario) {
    mario->AddCoin(1);
    mario->AddScore(200);
}
