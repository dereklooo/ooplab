//
// Created by benson on 2025/5/17.
//

#ifndef HORIZONTALELEVATOR_HPP
#define HORIZONTALELEVATOR_HPP
#warning "HorizontalElevator.cpp is being compiled"
#include "Object/SceneObject.hpp"


class HorizontalElevator final : public SceneObject {
    public:
        explicit HorizontalElevator(const glm::vec2 &position);
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

                return BlockType::HorizontalElevator;

        };
        void hit(const std::shared_ptr<Mario> &Mario) override;
    private:
        Way way = Way::Left;
        bool Moving = false;
        int MoveLong = 48*5;
        int movecenter = 48*5;
};
#endif //HORIZONTALELEVATOR_HPP
