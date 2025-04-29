//
// Created by Benson on 2025/4/29.
//
#include "Block/Pipe_64_128.hpp"
Pipe64_128::Pipe64_128(const glm::vec2 position) :  Pipe(RESOURCE_DIR"/image/Background/Level1/Block/Pipe_64_128.png" , position) {

}
void Pipe64_128::hit(const std::shared_ptr<Mario> &Mario) {
        (void)Mario;
}
