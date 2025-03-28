//
// Created by benson on 2025/3/14.
//

#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "Object/AnimationObject.hpp"
#include "Object/StillObject.hpp"

class Monster : public AnimationObject {
    public:
      Monster(const size_t size,std::string Path) : AnimationObject(size,Path) {};
      virtual void Action() = 0;
      virtual void Hurt() = 0;
    protected:

};
#endif //MONSTER_HPP
