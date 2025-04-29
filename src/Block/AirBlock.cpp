//
// Created by Benson on 2025/4/29.
//
#include "Block/AirBlock.hpp"
AirBlock::AirBlock(const glm::vec2& Position): SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/AirBlock.png", Position) {

}

void AirBlock::hit(const std::shared_ptr<Mario> &_)  {
    (void)_;
}