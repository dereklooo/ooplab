//
// Created by Benson on 2025/4/29.
//

#ifndef FLOORBLOCK_HPP
#define FLOORBLOCK_HPP
#include "Object/SceneObject.hpp"
class FloorBlock final : public SceneObject {
public:
    explicit FloorBlock(const glm::vec2& Position);

    void hit(const std::shared_ptr<Mario> &_) override;
    BlockType GetType() override {
        return BlockType::Floor;
    }
};
#endif //FLOORBLOCK_HPP
