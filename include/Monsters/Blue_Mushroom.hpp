//
// Created by Benson on 2025/5/24.
//

#ifndef BLUE_MUSHROOM_HPP
#define BLUE_MUSHROOM_HPP
#include "Monsters/Monster.hpp"
class Blue_Mushroom : public Monster{
public:
    Blue_Mushroom(const glm::vec2 position, const Way way) : Monster(2,RESOURCE_DIR"/image/character/monster/Blue_mushroom/mushroom_walk") {
        this->type = Mushroom_Type;
        this->SetWay(way);
        this->SetZIndex(100);
        this->SetPosition(position);
    };
    void Hurt() override;
    void Action() override;


private:
    std::shared_ptr<AnimationObject> walk = std::make_shared<AnimationObject>(2,RESOURCE_DIR "/image/character/monster/Blue_mushroom/mushroom_walk");
    std::shared_ptr<AnimationObject> die = std::make_shared<AnimationObject>(1,RESOURCE_DIR "/image/character/monster/Blue_mushroom/mushroom_die");
};
#endif //BLUE_MUSHROOM_HPP
