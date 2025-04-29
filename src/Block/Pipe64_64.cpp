//
// Created by Benson on 2025/4/29.
//
#include "Block/Pipe_64_64.hpp"
Pipe64_64::Pipe64_64(const glm::vec2 position) : Pipe(RESOURCE_DIR"/image/Background/Level1/Block/Pipe_64_64.png",position) {

}
void Pipe64_64::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}
