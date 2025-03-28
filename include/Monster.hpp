//
// Created by benson on 2025/3/14.
//

#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "AnimationObject.hpp"
#include "StillObject.hpp"

// #include "Monsters/Black_turtle.hpp"
// #include "Monsters/Eat_flower.hpp"
// #include "Monsters/Fly_turtle.hpp"
// #include "Monsters/Jump_turtle.hpp"
// #include "Monsters/Kooper.hpp"
// #include "Monsters/Mushroom.hpp"
// #include "Monsters/Turtle.hpp"
class Monster : public AnimationObject {
    public:
      Monster(const size_t size,std::string Path) : AnimationObject(size,Path) {};
      virtual void Action() = 0;
      virtual void Hurt() = 0;
    protected:

};
#endif //MONSTER_HPP
