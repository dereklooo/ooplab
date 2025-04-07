//
// Created by benson on 2025/3/14.
//

#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "Object/AnimationObject.hpp"
#include "Object/StillObject.hpp"
enum Way {Right ,Left};
class Monster : public AnimationObject {
    public:
      Monster(const size_t size,const std::string &Path) : AnimationObject(size,Path) {};
      void SetWay(Way way) {
          this->way = way;
          if(way == Right) {
              this->SetSize({1.2,1.2});
          }
          else if(way == Left) {
              this->SetSize({-1.2,1.2});
          }
      }

      Way GetWay() {
          return this->way;
      }

      virtual void Action() = 0;
      virtual void Hurt() = 0;
    protected:
        Way way;
};
#endif //MONSTER_HPP
