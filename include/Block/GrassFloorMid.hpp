#ifndef GRASSFLOORMID_HPP
#define GRASSFLOORMID_HPP

#include "Object/SceneObject.hpp"
class GrassFloorMid final : public SceneObject{
public:
    explicit GrassFloorMid(const glm::vec2 &Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override{return BlockType::GrassFloorMid;}
};

#endif //GRASSFLOORMID_HPP
