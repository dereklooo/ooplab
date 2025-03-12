//
// Created by Benson on 2025/3/9.
//

#ifndef ANIMATIONOBJECT_HPP
#define ANIMATIONOBJECT_HPP

#include <string>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"
enum Way {left,right};
class AnimationObject : public Util::GameObject{
public:
    AnimationObject(const size_t size,std::string Path){
        for(size_t i = 1;i <= size;i++) {
            AddImagePath(Path + std::to_string(i) + ".png");
        }
        m_Drawable = std::make_shared<Util::Animation>(AnimationPaths,true,100,true,20);
    }

    Way GetWay(){return way;}

    glm::vec2 GetPosition() {return m_Transform.translation;}

    void SetWay(Way way){this->way = way;}

    void SetPosition(const glm::vec2 &position) {m_Transform.translation = position;}

    void SetSize(glm::vec2 size) {m_Transform.scale = size;}

    void AddImagePath(std::string ImagePath) {
        AnimationPaths.push_back(ImagePath);
    }

    std::shared_ptr<Core::Drawable> GetDrawable() {return m_Drawable;}

protected:
    std::shared_ptr<Util::Animation> Animations;
    std::vector<std::string> AnimationPaths;
    Way way;
};
#endif //ANIMATIONOBJECT_HPP
