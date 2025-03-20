//
// Created by benson on 2025/3/14.
//

#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "AnimationObject.hpp"

// #include "Monsters/Black_turtle.hpp"
// #include "Monsters/Eat_flower.hpp"
// #include "Monsters/Fly_turtle.hpp"
// #include "Monsters/Jump_turtle.hpp"
// #include "Monsters/Kooper.hpp"
// #include "Monsters/Mushroom.hpp"
// #include "Monsters/Turtle.hpp"

class Monster : public AnimationObject {
    public:
      Monster();
      void SetMonsterVect(std::vector<std::shared_ptr<Monster>> monsters) {
          this->monsters() = monsters;
      };
      virtual void Action() = 0;
      virtual void GotHit() = 0;
    private:
        std::vector<std::shared_ptr<Monster>> monsters();
};
#endif //MONSTER_HPP
