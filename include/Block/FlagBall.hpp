//
// Created by 羅健文 on 2025/5/10.
//

#ifndef FLAGBALL_HPP
#define FLAGBALL_HPP
#include "Object/SceneObject.hpp"
#include "Util/Time.hpp"
class FlagBall : public SceneObject {
public:
    explicit FlagBall(glm::vec2 Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override {return BlockType::flagball;};


private:
};
#endif //FLAGBALL_HPP
