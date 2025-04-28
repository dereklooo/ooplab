//
// Created by benson on 2025/3/14.
//

#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "Object/AnimationObject.hpp"
#include "Object/StillObject.hpp"
#include "Util/Time.hpp"

enum MonsterType {
    Black_turtle,
    Eat_flower,
    Fly_turtle,
    Kooper,
    Jump_turtle,
    Mushroom_Type,
    Turtle_Type
};

class Monster : public AnimationObject {
    public:
      Monster(const size_t size,const std::string &Path) : AnimationObject(size,Path) {};
      void SetWay(const Way way) {
          this->way = way;
          if(way == Right) {
              this->SetSize({1.2,1.2});
          }
          else if(way == Left) {
              this->SetSize({-1.2,1.2});
          }
      }

      Way GetWay() const {
          return this->way;
      }
      bool GetDie() const {
          return Die;
      }
      MonsterType GetType() const {
          return type;
      };
      virtual void Action() = 0;
      virtual void Hurt() = 0;
    protected:
        Way way;
        bool Die = false;
        float StartHurtTimer = 0.0f;
        MonsterType type;

};
#endif //MONSTER_HPP
