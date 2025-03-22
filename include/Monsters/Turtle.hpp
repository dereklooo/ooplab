//
// Created by benson on 2025/3/17.
//

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Monster.hpp"
class Turtle : public Monster{
    public:
        Turtle(const size_t size,std::string Path) : Monster(size,Path){};
        void Action() override;
        void GotHit() override;
    private:
        std::shared_ptr<AnimationObject> walk = std::make_shared<AnimationObject>(2,RESOURCE_DIR "/image/character/monster/turtle/walk");
        std::shared_ptr<StillObject> die = std::make_shared<StillObject>(RESOURCE_DIR "/image/character/monster/turtle/die1.png");
};
#endif //TURTLE_HPP
