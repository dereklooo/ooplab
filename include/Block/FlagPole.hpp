//
// Created by 羅健文 on 2025/5/10.
//

#ifndef FLAGPOLE_HPP
#define FLAGPOLE_HPP
#include "Object/SceneObject.hpp"
#include "Util/Time.hpp"
class FlagPole : public SceneObject {
public:
    explicit FlagPole(glm::vec2 Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override {return BlockType::flagpole;};



private:
    std::shared_ptr<Util::Time> time;
};
#endif //FLAGPOLE_HPP
