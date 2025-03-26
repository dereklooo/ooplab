//
// Created by benson on 2025/3/25.
//

#ifndef ORIGINALBLOCK_HPP
#define ORIGINALBLOCK_HPP
#include "SceneObject.hpp"
class OriginalBlock : public ScenceObject {
    public:
    OriginalBlock(glm::vec2 Position) : ScenceObject("/image/Background/Level1/Block/OriginalBlock.png",Position) {

    }
};
#endif //ORIGINALBLOCK_HPP
