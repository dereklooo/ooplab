//
// Created by benson on 2025/3/14.
//

#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "AnimationObject.hpp"
class Monster : public AnimationObject {
    public:
      virtual void Action() = 0;
      virtual void GotHit() = 0;
    private:

};
#endif //MONSTER_HPP
