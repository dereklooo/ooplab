//
// Created by benson on 2025/3/25.
//

#ifndef LUCKYBLOCK_HPP
#define LUCKYBLOCK_HPP
#include "Block/Block.hpp"
enum State {

};
class LuckyBlock : public Block{
    public:
        LuckyBlock(const glm::vec2 &Position) : Block(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock.png",Position) {

        }
        void ChangeState() {
            this->SetImagePath(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock_.png");
        }
        void hit(std::shared_ptr<Mario> Mario) override{
            this->ChangeState();
        }
};
#endif //LUCKYBLOCK_HPP
