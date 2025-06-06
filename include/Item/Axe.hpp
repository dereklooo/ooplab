//
// Created by Benson on 2025/5/27.
//

#ifndef AXE_HPP
#define AXE_HPP
#include "Object/ItemObject.hpp"
#include "Object/SceneObject.hpp"
class Axe final : public ItemObject {
    public:
        explicit Axe(const glm::vec2 &position);
        void ConnectToBlock(const std::shared_ptr<SceneObject>& block);
        void Action() override;
        void ChangeMarioState(std::shared_ptr<Mario> &mario) override;
    private:
        float StartCollision = 0.0f;
        bool Collision = false;
        std::vector<std::shared_ptr<SceneObject>> Bridges;
        std::shared_ptr<Mario> Mario_ = nullptr;
};
#endif //AXE_HPP
