//
// Created by benson on 2025/5/25.
//
#include "Block/BlueOriginalCoin.hpp"

BlueOriginalCoin::BlueOriginalCoin(const glm::vec2 &Position) : OriginalCoin(Position){
    this->SetDrawable(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/Level1/Block/BlueOriginalBlock.png"));
}
