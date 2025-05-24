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
        this->SetDrawable(WalkDrawable);
        this->SetWay(way);
        this->SetSize({1.5,1.5});
        this->SetZIndex(100);
        this->SetPosition(position);
    };
private:
    TurtleType Turtle_type;

    std::shared_ptr<Util::Animation> WalkDrawable = BlueTurtle::GenerateAnimation(2,RESOURCE_DIR "/image/character/monster/Blue_turtle/walk",200,100);
    std::shared_ptr<Util::Image> DieDrawable1= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/Blue_turtle/die1.png");
    std::shared_ptr<Util::Image> DieDrawable2= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/Blue_turtle/die2.png");
};
#endif //BLUETURTLE_HPP
