//
// Created by benson on 2025/3/25.
//

#ifndef LUCKYBLOCK_HPP
#define LUCKYBLOCK_HPP
#include "SceneObject.hpp"
class LuckyBlock : public SceneObject{
    public:
        LuckyBlock(glm::vec2 Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock.png",Position) {

        }
        void ChangeState() {
            this->SetImagePath(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock_.png");
        }
        void hit() override {
            this->ChangeState();
        }
};
#endif //LUCKYBLOCK_HPP
