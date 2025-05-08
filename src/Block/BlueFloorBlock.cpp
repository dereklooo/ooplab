//
// Created by benson on 2025/5/8.
//
#include "Block/BlueFloorBlock.hpp"
BlueFloorBlock::BlueFloorBlock(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/BlueFloor.png", Position){

}

void BlueFloorBlock::hit(const std::shared_ptr<Mario> &_) {
    (void)_;
}