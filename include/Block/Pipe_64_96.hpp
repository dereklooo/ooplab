//
// Created by benson on 2025/3/25.
//

#ifndef PIPE_64_96_HPP
#define PIPE_64_96_HPP
#include "Object/SceneObject.hpp"
class Pipe64_96 : public SceneObject {
public:
    Pipe64_96(glm::vec2 position) :  SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/Pipe_64_96.png" , position) {

    }
    void hit(const std::shared_ptr<Mario> &Mario) override {
        return;
    };
};
#endif //PIPE_64_96_HPP
