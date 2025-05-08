//
// Created by benson on 2025/5/8.
//
#include "Block/LongPipe.hpp"
LongPipe::LongPipe(glm::vec2 position) : Pipe(RESOURCE_DIR"/image/Background/Level1/Block/LongPipe.png",position){

}
void LongPipe::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}

