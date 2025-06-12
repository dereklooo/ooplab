//
// Created by 羅健文 on 2025/6/2.
//

#ifndef RED_TURTLE_HPP
#define RED_TURTLE_HPP

#include "Monsters/Turtle.hpp"
class RedTurtle final : public Turtle{
public:
    RedTurtle(const glm::vec2 position, const Way way) : Turtle(position,way) {
        this->type = MonsterType::Red_turtle;
        this->Turtle_type = TurtleType::OutSide;
        WalkDrawable = RedTurtle::GenerateAnimation(2,RESOURCE_DIR "/image/character/monster/red_turtle/walk",200,100);
        this->SetDrawable(WalkDrawable);
        DieDrawable1= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/red_turtle/die1.png");
        DieDrawable2= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/red_turtle/die2.png");
        this->SetWay(way);
        this->SetSize({1.5,1.5});
        this->SetZIndex(100);
        this->SetPosition(position);
    };
    void Action() override;
    void Hurt() override;

};

#endif //RED_TURTLE_HPP
