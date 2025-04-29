//
// Created by benson on 2025/4/10.
//

#ifndef AIRBLOCK_HPP
#define AIRBLOCK_HPP
#include "Object/SceneObject.hpp"

class AirBlock final : public SceneObject {
public:
    explicit AirBlock(const glm::vec2& Position);

    void hit(const std::shared_ptr<Mario> &_) override;
    BlockType GetType() override {
        return BlockType::Air;
    }
};

#endif //AIRBLOCK_HPP
