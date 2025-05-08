//
// Created by benson on 2025/5/8.
//

#ifndef BLUEFLOORBLOCK_HPP
#define BLUEFLOORBLOCK_HPP
#include "Object/SceneObject.hpp"
class BlueFloorBlock final : public SceneObject {
public:
    explicit BlueFloorBlock(const glm::vec2& Position);

    void hit(const std::shared_ptr<Mario> &_) override;
    BlockType GetType() override {
        return BlockType::Blue_Floor;
    }
};
#endif //BLUEFLOORBLOCK_HPP
