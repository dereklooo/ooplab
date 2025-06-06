//
// Created by benson on 2025/5/17.
//

#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP
#include "Object/SceneObject.hpp"

class Elevator final : public SceneObject {
    public:
        explicit Elevator(const glm::vec2 &position,Way way);
        void Move();
        Way GetWay() const {
            return way;
        }
        bool GetMove() {
            return Moving;
        }
        void SetWay(const Way way) {
            this->way = way;
        }
        void SetMove(const bool M) {
            Moving = M;
        }
        BlockType GetType() override {
            if(this->way == Left) {
                return BlockType::Elevator_Down;
            }
            else {
                return BlockType::Elevator_Up;
            }
        };
        void hit(const std::shared_ptr<Mario> &Mario) override;
    private:
        Way way = Way::Left;
        bool Moving = false;
};
#endif //ELEVATOR_HPP
