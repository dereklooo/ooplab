//
// Created by benson on 2025/3/25.
//

#ifndef FOOTBLOCK_HPP
#define FOOTBLOCK_HPP
#include "Block/Block.hpp"
class FootBlock : public  Block{
    public:
        FootBlock(const glm::vec2 &Position) : Block(RESOURCE_DIR"/image/Background/Level1/Block/FootBlock.png",Position) {

        }
        void hit() override {

        }
};
#endif //FOOTBLOCK_HPP
