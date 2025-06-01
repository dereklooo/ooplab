#include "Block/GrassFloorRight.hpp"
GrassFloorRight::GrassFloorRight(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level3/Block/grassfloorright.png",Position) {

}
void GrassFloorRight::hit(const std::shared_ptr<Mario> &Mario)  {
    (void)Mario;
}
