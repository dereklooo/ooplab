//
// Created by benson on 2025/5/17.
//

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP
#include "Object/SceneObject.hpp"

class Elevator : public SceneObject {
    public:
        explicit Elevator(const glm::vec2 &position);
        void Move();
        Way GetWay() const {
            return way;
        }
        void SetWay(const Way way) {
            this->way = way;
        }
        BlockType GetType() override {return BlockType::Elevator;};
        void hit(const std::shared_ptr<Mario> &Mario) override;
    private:
        Way way = Way::Left;
};
#endif //ELEVATOR_HPP
