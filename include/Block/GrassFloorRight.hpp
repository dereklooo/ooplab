#ifndef GRASSFLOORRIGHT_HPP
#define GRASSFLOORRIGHT_HPP

#include "Object/SceneObject.hpp"
class GrassFloorRight final : public SceneObject{
public:
    explicit GrassFloorRight(const glm::vec2 &Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override{return BlockType::GrassFloorRight;}
};

#endif //GRASSFLOORRIGHT_HPP
