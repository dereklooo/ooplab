//
// Created by benson on 2025/3/25.
//

#ifndef FOOTBLOCK_HPP
#define FOOTBLOCK_HPP
#include "Object/SceneObject.hpp"
class FootBlock : public SceneObject{
    public:
        FootBlock(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/FootBlock.png",Position) {

        }
        void hit(const std::shared_ptr<Mario> &Mario) override {
            (void)Mario;
        }
        BlockType GetType() override{return BlockType::Foot;}
};
#endif //FOOTBLOCK_HPP
