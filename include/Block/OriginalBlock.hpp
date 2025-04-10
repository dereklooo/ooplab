//
// Created by benson on 2025/3/25.
//

#ifndef ORIGINALBLOCK_HPP
#define ORIGINALBLOCK_HPP
#include "Block/Block.hpp"
class OriginalBlock : public Block {
    public:
    OriginalBlock(glm::vec2 Position) : Block(RESOURCE_DIR"/image/Background/Level1/Block/OriginalBlock.png",Position) {

    }
    void hit() override {
        this->SetSize({0,0});
        this->SetVisible(false);
    }
};
#endif //ORIGINALBLOCK_HPP
