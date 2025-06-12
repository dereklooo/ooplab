//
// Created by benson on 2025/3/17.
//

#ifndef FLY_TURTLE_HPP
#define FLY_TURTLE_HPP
#include "Monster.hpp"
#include "Monsters/Turtle.hpp"
#include <iostream>
class FlyTurtle final : public Turtle{
public:
    FlyTurtle(const glm::vec2 position, const Way way) : Turtle(position,way) {
        this->type = MonsterType::Fly_turtle;
        this->Turtle_type = TurtleType::Flying;
        WalkDrawable = FlyTurtle::GenerateAnimation(2,RESOURCE_DIR "/image/character/monster/red_turtle/walk",200,100);
        this->SetDrawable(WalkDrawable);
        DieDrawable1= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/red_turtle/die1.png");
        DieDrawable2= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/red_turtle/die2.png");
        this->SetWay(way);
        this->SetSize({1.5,1.5});
        this->SetZIndex(100);
        this->SetPosition(position);
        this->SetDrawable(this->FlyDrawable);
    };
    void Action() override;
    void Hurt() override;
private:

    std::shared_ptr<Util::Animation> FlyDrawable = Turtle::GenerateAnimation(2,RESOURCE_DIR "/image/character/monster/fly_turtle/fly",200,100);

};
#endif //FLY_TURTLE_HPP
