#include "Block/GrassFloorLeft.hpp"
GrassFloorLeft::GrassFloorLeft(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level3/Block/grassfloorleft.png",Position) {

}
void GrassFloorLeft::hit(const std::shared_ptr<Mario> &Mario)  {
    (void)Mario;
}