//
// Created by benson on 2025/3/25.
//

#ifndef FOOTBLOCK_HPP
#define FOOTBLOCK_HPP
#include "Object/SceneObject.hpp"
class FootBlock final : public SceneObject{
    public:
        explicit FootBlock(const glm::vec2 &Position);
        void hit(const std::shared_ptr<Mario> &Mario) override;
        BlockType GetType() override{return BlockType::Foot;}
};
#endif //FOOTBLOCK_HPP
