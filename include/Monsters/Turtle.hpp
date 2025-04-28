//
// Created by benson on 2025/3/17.
//

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Monster.hpp"
enum TurtleType {
    OutSize,
    Inside,
    Rolling,
};
class Turtle final : public Monster{
    public:
        Turtle(const glm::vec2 position, const Way way) : Monster(2,RESOURCE_DIR"/image/character/monster/turtle/walk") {
            this->type = MonsterType::Turtle_Type;
            this->Turtle_type = TurtleType::OutSize;
            this->SetWay(way);
            this->SetSize({3,2.5});
            this->SetZIndex(100);
            this->SetPosition(position);
        };
        void Action() override;
        void Hurt() override;
    private:
        TurtleType Turtle_type;

        std::shared_ptr<AnimationObject> walk = std::make_shared<AnimationObject>(2,RESOURCE_DIR "/image/character/monster/turtle/walk");
        std::shared_ptr<StillObject> die = std::make_shared<StillObject>(RESOURCE_DIR "/image/character/monster/turtle/die1.png");
};
#endif //TURTLE_HPP
