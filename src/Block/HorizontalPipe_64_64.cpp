//
// Created by Benson on 2025/5/8.
//
#include "Block/HorizontalPipe_64_64.hpp"
HorizontalPipe_64_64::HorizontalPipe_64_64(const glm::vec2 position,Way way) : Pipe(RESOURCE_DIR"/image/Background/Level1/Block/HorizontalPipe_64_64.png",position) {
    this->way = way;
}
void HorizontalPipe_64_64::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}