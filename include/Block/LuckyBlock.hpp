//
// Created by benson on 2025/3/25.
//

#ifndef LUCKYBLOCK_HPP
#define LUCKYBLOCK_HPP
#include "Object/SceneObject.hpp"
class LuckyBlock : public SceneObject{
    public:
        explicit LuckyBlock(const glm::vec2 &Position);
        void ChangeState();
        void hit(const std::shared_ptr<Mario> &Mario) override;
        BlockType GetType() override{return BlockType::Lucky;}
};
#endif //LUCKYBLOCK_HPP
