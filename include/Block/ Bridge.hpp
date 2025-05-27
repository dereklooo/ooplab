//
// Created by Benson on 2025/5/27.
//

#ifndef BRIDGE_HPP
#define BRIDGE_HPP
#include "Object/SceneObject.hpp"
class Bridge : public SceneObject {
    public:
        explicit Bridge(const glm::vec2 &Position);
        void hit(const std::shared_ptr<Mario> &Mario) override;
        void Break();
        BlockType GetType() override;
    private:
};
#endif //BRIDGE_HPP
