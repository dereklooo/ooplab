//
// Created by benson on 2025/5/8.
//

#ifndef BLUEFOOTBLOCK_HPP
#define BLUEFOOTBLOCK_HPP
#include "Object/SceneObject.hpp"
class BlueFootBlock final : public SceneObject{
public:
    explicit BlueFootBlock(const glm::vec2 &Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override{return BlockType::Blue_Foot;}
};
#endif //BLUEFOOTBLOCK_HPP
