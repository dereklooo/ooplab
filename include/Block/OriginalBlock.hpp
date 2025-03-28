//
// Created by benson on 2025/3/25.
//

#ifndef ORIGINALBLOCK_HPP
#define ORIGINALBLOCK_HPP
#include "Object/SceneObject.hpp"
class OriginalBlock : public SceneObject {
    public:
    OriginalBlock(glm::vec2 Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/OriginalBlock.png",Position) {

    }
    void hit() {
        this->SetPosition(this->GetPosition());
    }
};
#endif //ORIGINALBLOCK_HPP
