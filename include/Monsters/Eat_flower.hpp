//
// Created by benson on 2025/3/17.
//

#ifndef EAT_FLOWER_HPP
#define EAT_FLOWER_HPP
#include "Monster.hpp"
enum Side {In,Out};
class EatFlower final : public Monster {
    public:
        explicit EatFlower(glm::vec2 position);
        void SetSide(Side s) {
            side = s;
        }
        Side GetSide() const {
                return side;
        }
        void Hurt() override;
        void Action() override;
    private:
        Side side = In;
        float delta;
};
#endif //EAT_FLOWER_HPP
