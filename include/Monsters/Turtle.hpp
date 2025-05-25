//
// Created by benson on 2025/3/17.
//

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Monster.hpp"
class Turtle : public Monster{
    public:
        Turtle(const glm::vec2 position, const Way way) : Monster(2,RESOURCE_DIR"/image/character/monster/turtle/walk") {
            this->type = MonsterType::Turtle_Type;
            this->Turtle_type = TurtleType::OutSide;
            this->SetWay(way);
            this->SetSize({1.2,1.25});
            this->SetZIndex(100);
            this->SetPosition(position);
        };
        void Action() override;
        void Hurt() override;
        TurtleType GetTurtleTye() const {
            return Turtle_type;
        }
    protected:
        TurtleType Turtle_type;

        std::shared_ptr<Util::Animation> WalkDrawable = Turtle::GenerateAnimation(2,RESOURCE_DIR "/image/character/monster/turtle/walk",200,100);
        std::shared_ptr<Util::Image> DieDrawable1= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/turtle/die1.png");
        std::shared_ptr<Util::Image> DieDrawable2= std::make_shared<Util::Image>(RESOURCE_DIR "/image/character/monster/turtle/die2.png");
};
#endif //TURTLE_HPP
