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
    Kooper_Type,
    Jump_turtle,
    Mushroom_Type,
    Turtle_Type,
    Red_turtle
};

enum TurtleType {
    OutSide,
    Inside,
    Rolling,
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
      void SetDie(bool D){
          this->Die = D;
      }
      MonsterType GetType() const {
          return type;
      }
      bool GetKnockAway() const {
          return KnockAway;
      }
        void SetKnockAway(const bool KnockAway) {
          this->KnockAway = KnockAway;
      }
      virtual void Action() = 0;
      virtual void Hurt() = 0;
    protected:
        Way way;
        bool Die = false;
        bool KnockAway = false;
        float StartHurtTimer = 0.0f;
        MonsterType type;

};
#endif //MONSTER_HPP
