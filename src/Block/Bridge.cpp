//
// Created by Benson on 2025/5/27.
//
#include "Block/ Bridge.hpp"
Bridge::Bridge(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level4/Block/Bridge.png",Position){

}
void Bridge::Break() {
    this->SetSize({0,0});
}
BlockType Bridge::GetType() {
    return BlockType::Bridge;
}
void Bridge::hit(const std::shared_ptr<Mario> &Mario) {
    (void)Mario;
}


