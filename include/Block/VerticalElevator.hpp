//
// Created by benson on 2025/5/17.
//

#ifndef VERTICALELEVATOR_HPP
#define VERTICALELEVATOR_HPP
#include "Object/SceneObject.hpp"

class VerticalElevator final : public SceneObject {
    public:
        explicit VerticalElevator(const glm::vec2 &position);
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
        void SetMoveLong(const int L){
            MoveLong = L;
        }
        BlockType GetType() override {

                return BlockType::VerticalElevator;

        };
        void hit(const std::shared_ptr<Mario> &Mario) override;
    private:
        Way way = Way::up;
        bool Moving = false;
        int movecenter = 0;
        int MoveLong = 0;
};
#endif //VERTICALELEVATOR_HPP
