//
// Created by 羅健文 on 2025/5/2.
//

#ifndef FLAG_HPP
#define FLAG_HPP
#include "Object/SceneObject.hpp"
#include "Util/Time.hpp"
class Flag : public SceneObject {
public:
    explicit Flag(glm::vec2 Position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override {return BlockType::flag;};

private:
    std::shared_ptr<Util::Time> time;
};
#endif //FLAG_HPP
