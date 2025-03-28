//
// Created by benson on 2025/3/25.
//

#ifndef ORIGINALBLOCK_HPP
#define ORIGINALBLOCK_HPP
#include "SceneObject.hpp"
class OriginalBlock : public SceneObject {
    public:
    OriginalBlock(glm::vec2 Position) : SceneObject("/image/Background/Level1/Block/OriginalBlock.png",Position) {

    }
    void hit() override{
        this->SetPosition(this->GetPosition());
    }
};
#endif //ORIGINALBLOCK_HPP
