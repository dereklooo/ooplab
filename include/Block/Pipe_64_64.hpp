//
// Created by benson on 2025/3/25.
//

#ifndef PIPE_64_64_HPP
#define PIPE_64_64_HPP
#include "Object/SceneObject.hpp"
class Pipe64_64 : public SceneObject {
public:
    Pipe64_64(glm::vec2 position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/Pipe_64_64.png",position) {

    }
    void hit(const std::shared_ptr<Mario> &Mario) override {
        (void)Mario;
    };
};
#endif //PIPE_64_64_HPP
