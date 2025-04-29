//
// Created by Benson on 2025/4/29.
//
#include "Block/Pipe_64_96.hpp"
Pipe64_96::Pipe64_96(const glm::vec2 position) : Pipe(RESOURCE_DIR"/image/Background/Level1/Block/Pipe_64_96.png",position) {

}
void Pipe64_96::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}

