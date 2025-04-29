//
// Created by Benson on 2025/4/29.
//
//
// Created by Benson on 2025/4/29.
//
#include "Block/FloorBlock.hpp"
FloorBlock::FloorBlock(const glm::vec2& Position): SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/Floor.png", Position) {

}

void FloorBlock::hit(const std::shared_ptr<Mario> &_)  {
    (void)_;
}