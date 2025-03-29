//
// Created by benson on 2025/3/25.
//

#ifndef PIPE_64_128_HPP
#define PIPE_64_128_HPP
#include "Object/SceneObject.hpp"
class Pipe64_128 : public SceneObject {
public:
    Pipe64_128(glm::vec2 position) :  SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/Pipe_64_128.png" , position) {

    }
};
#endif //PIPE_64_128_HPP
