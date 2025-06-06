//
// Created by benson on 2025/3/25.
//

#ifndef ORIGINALBLOCK_HPP
#define ORIGINALBLOCK_HPP
#include "Object/SceneObject.hpp"
#include "Util/Time.hpp"
class OriginalBlock : public SceneObject {
    public:
    explicit OriginalBlock(glm::vec2 Position);
    void ChangeState();
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override {return BlockType::Original;};
    private:
        std::shared_ptr<Util::Time> time;
};
#endif //ORIGINALBLOCK_HPP
