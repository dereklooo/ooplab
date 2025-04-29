//
// Created by Benson on 2025/4/29.
//
#include "Block/FootBlock.hpp"
FootBlock::FootBlock(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/FootBlock.png",Position) {

}
void FootBlock::hit(const std::shared_ptr<Mario> &Mario)  {
    (void)Mario;
}
