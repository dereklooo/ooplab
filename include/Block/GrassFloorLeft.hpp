#ifndef GRASSFLOORLEFT_HPP
#define GRASSFLOORLEFT_HPP

#include "Object/SceneObject.hpp"
class GrassFloorLeft final : public SceneObject{
public:
    explicit GrassFloorLeft(const glm::vec2 &Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override{return BlockType::GrassFloorLeft;}
};

#endif //GRASSFLOORLEFT_HPP
