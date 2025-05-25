//
// Created by Benson on 2025/5/24.
//

#ifndef BLUETURTLE_HPP
#define BLUETURTLE_HPP
#include "Monsters/Turtle.hpp"
class BlueTurtle final : public Turtle{
public:
    BlueTurtle(const glm::vec2 position, const Way way) : Turtle(position,way) {
        this->type = MonsterType::Turtle_Type;
        this->Turtle_type = TurtleType::OutSide;
        WalkDrawable = BlueTurtle::GenerateAnimation(2,RESOURCE_DIR "/image/character/monster/Blue_turtle/walk",200,100);
        this->SetDrawable(WalkDrawable);
        DieDrawable1= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/Blue_turtle/die1.png");
        DieDrawable2= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/Blue_turtle/die2.png");
        this->SetWay(way);
        this->SetSize({1.5,1.5});
        this->SetZIndex(100);
        this->SetPosition(position);
    };
private:
    TurtleType Turtle_type;
};
#endif //BLUETURTLE_HPP
