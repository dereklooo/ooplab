//
// Created by benson on 2025/5/8.
//
#include "Block//BlueFootBlock.hpp"

BlueFootBlock::BlueFootBlock(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/BlueFootBlock.png",Position){

}
void BlueFootBlock::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}

