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
      Monster(const size_t size,std::string Path) : AnimationObject(size,Path) {};
      void SetWay(Way way) {
          this->way = way;
      }

      Way GetWay() {
          return this->way;
      }

       bool Collision(const std::shared_ptr<GameObject> &other) {
             if (
                 other->GetTransform().translation.x + (other->GetScaledSize().x / 2) >= this->GetTransform().translation.x - abs(this->GetScaledSize().x / 2) &&
                 other->GetTransform().translation.x - (other->GetScaledSize().x / 2) <= this->GetTransform().translation.x + abs(this->GetScaledSize().x / 2) &&
                 other->GetTransform().translation.y + (other->GetScaledSize().y / 2) >= this->GetTransform().translation.y - abs(this->GetScaledSize().y / 2) &&
                 other->GetTransform().translation.y - (other->GetScaledSize().y / 2) <= this->GetTransform().translation.y + abs(this->GetScaledSize().y / 2)
             ) {
                 return true;
             }
          return false;
       }

      virtual void Action() = 0;
      virtual void Hurt() = 0;
    protected:
        Way way;
};
#endif //MONSTER_HPP
