#ifndef TREEWALL_HPP
#define TREEWALL_HPP

#include "Object/SceneObject.hpp"
class TreeWall final : public SceneObject{
public:
    explicit TreeWall(const glm::vec2 &Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override{return BlockType::TreeWall;}
};


#endif //TREEWALL_HPP
