#include "Block/TreeWall.hpp"
TreeWall::TreeWall(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level3/Block/treewall.png",Position) {

}
void TreeWall::hit(const std::shared_ptr<Mario> &Mario)  {
    (void)Mario;
}
