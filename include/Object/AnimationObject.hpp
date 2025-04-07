//
// Created by Benson on 2025/3/9.
//

#ifndef ANIMATIONOBJECT_HPP
#define ANIMATIONOBJECT_HPP

#include <string>

#include "Object.hpp"
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
class AnimationObject : public Object{
public:
    AnimationObject(const size_t size,const std::string &Path){
        for(size_t i = 1;i <= size;i++) {
            AddImagePath(Path + std::to_string(i) + ".png");
        }
        m_Drawable = std::make_shared<Util::Animation>(AnimationPaths,true,100,true,20);
    }

    static std::shared_ptr<Util::Animation> GenerateAnimation(const size_t size,const std::string &Path,size_t interval,size_t cooldown) {
        std::vector<std::string> Paths;
        for(size_t i = 1;i <= size;i++) {
            Paths.push_back(Path + std::to_string(i) + ".png");
        }
        return  std::make_shared<Util::Animation>(Paths,true,interval,true,cooldown);
    }

    void AddImagePath(const std::string &ImagePath) {
        AnimationPaths.push_back(ImagePath);
    }
protected:
    std::shared_ptr<Util::Animation> Animations;
    std::vector<std::string> AnimationPaths;
};
#endif //ANIMATIONOBJECT_HPP
