//
// Created by benson on 2025/3/17.
//

#ifndef FLY_TURTLE_HPP
#define FLY_TURTLE_HPP
#include "Monster.hpp"
#include "Monsters/Turtle.hpp"
class FlyTurtle final : public Turtle{
public:
    FlyTurtle(const glm::vec2 position, const Way way) : Turtle(position,way) {
        this->type = MonsterType::Red_turtle;
        this->Turtle_type = TurtleType::OutSide;
        WalkDrawable = FlyTurtle::GenerateAnimation(2,RESOURCE_DIR "/image/character/monster/fly_turtle/fly1",200,100);
        this->SetDrawable(WalkDrawable);
        DieDrawable1= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/red_turtle/die1.png");
        DieDrawable2= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/red_turtle/die2.png");
        this->SetWay(way);
        this->SetSize({1.5,1.5});
        this->SetZIndex(100);
        this->SetPosition(position);
    };
    void Action() override;
private:
    TurtleType Turtle_type;
};
#endif //FLY_TURTLE_HPP
