//
// Created by Benson on 2025/3/9.
//

#ifndef ANIMATIONOBJECT_HPP
#define ANIMATIONOBJECT_HPP

#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"

class AnimationObject : public Util::GameObject{
public:
    AnimationObject();
private:
    Util::Animation animation;
};
#endif //ANIMATIONOBJECT_HPP
