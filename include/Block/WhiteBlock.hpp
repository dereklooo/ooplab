//
// Created by benson on 2025/5/25.
//

#ifndef WHITEBLOCK_HPP
#define WHITEBLOCK_HPP
#include "Object/SceneObject.hpp"
class WhiteBlock final : public SceneObject {
public:
    explicit WhiteBlock(const glm::vec2 &Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override{return BlockType::White_Block;}
    private:

};
#endif //WHITEBLOCK_HPP
