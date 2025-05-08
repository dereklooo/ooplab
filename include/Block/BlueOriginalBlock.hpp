//
// Created by benson on 2025/5/8.
//

#ifndef BLUEORIGINALBLOCK_HPP
#define BLUEORIGINALBLOCK_HPP
#include "Object/SceneObject.hpp"
#include "Util/Time.hpp"
class BlueOriginalBlock final : public SceneObject {
public:
    explicit BlueOriginalBlock(glm::vec2 Position);
    void ChangeState();
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override {return BlockType::Blue_Original;};
private:
    float BouncingTimer = 0;
    bool Bouncing = false;
    std::shared_ptr<Util::Time> time;
};
#endif //BLUEORIGINALBLOCK_HPP
