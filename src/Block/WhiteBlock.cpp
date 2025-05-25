//
// Created by benson on 2025/5/25.
//
#include "Block/WhiteBlock.hpp"
WhiteBlock::WhiteBlock(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level4/Block/WhiteBlock.png",Position){

}
void WhiteBlock::hit(const std::shared_ptr<Mario> &Mario) {
    (void) Mario;
}

