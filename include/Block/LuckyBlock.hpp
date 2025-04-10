//
// Created by benson on 2025/3/25.
//

#ifndef LUCKYBLOCK_HPP
#define LUCKYBLOCK_HPP
#include "Object/SceneObject.hpp"
enum State {

};
class LuckyBlock : public SceneObject{
    public:
        LuckyBlock(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock.png",Position) {

        }
        void ChangeState() {
            this->SetDrawable(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock_.png"));
        }
        void hit(const std::shared_ptr<Mario> &Mario) override{
            this->ChangeState();
        }
};
#endif //LUCKYBLOCK_HPP
