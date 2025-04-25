//
// Created by benson on 2025/4/10.
//

#ifndef AIRBLOCK_HPP
#define AIRBLOCK_HPP
#include "Object/SceneObject.hpp"

class AirBlock final : public SceneObject {
public:
    AirBlock(const glm::vec2& Position): SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/AirBlock.png", Position) {}

    void hit(const std::shared_ptr<Mario> &_) override {
        (void)_;
    }
    BlockType GetType() override{return BlockType::Air;}
};

#endif //AIRBLOCK_HPP
