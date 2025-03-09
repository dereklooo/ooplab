//
// Created by Benson on 2025/3/9.
//

#ifndef ANIMATIONOBJECT_HPP
#define ANIMATIONOBJECT_HPP

#include <string>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"

class AnimationObject : public Util::GameObject{
public:
    AnimationObject(const size_t size,std::string Path){
        for(size_t i = 1;i <= size;i++) {
            AddImagePath(Path + std::to_string(i) + ".png");
        }
        Animations.push_back(std::make_shared<Util::Animation>(AnimationPaths,true,50,true,20));
    }

    void SetPosition(const glm::vec2 &position) {m_Transform.translation = position;}

    void SetSize(glm::vec2 size) {m_Transform.scale = size;}

    void AddImagePath(std::string ImagePath) {
        AnimationPaths.push_back(ImagePath);
    }


private:
    std::vector<std::shared_ptr<Util::Animation>> Animations;
    std::vector<std::string> AnimationPaths;
};
#endif //ANIMATIONOBJECT_HPP
