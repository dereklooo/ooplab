//
// Created by benson on 2025/3/17.
//

#ifndef EAT_FLOWER_HPP
#define EAT_FLOWER_HPP
#include "Monster.hpp"
#include "Mario/Mario.hpp"

enum Side {In,Out};
class EatFlower final : public Monster {
    public:
        explicit EatFlower(glm::vec2 position,std::shared_ptr<Mario>& Mario);
        void SetSide(Side s) {
            side = s;
        }
        Side GetSide() const {
            return side;
        }
        void SetOriginalPosition(glm::vec2 Pos);
        glm::vec2 GetOriginalPosition() const;
        void Hurt() override;
        void Action() override;
    private:
        Side side = In;
        float delta;
        glm::vec2 OriginalPosition;
        std::shared_ptr<Mario> mario;
};
#endif //EAT_FLOWER_HPP
