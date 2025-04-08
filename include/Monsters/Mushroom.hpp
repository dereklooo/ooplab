//
// Created by benson on 2025/3/17.
//

#ifndef MUSHROOM_HPP
#define MUSHROOM_HPP
#include "Monster.hpp"
class Mushroom : public Monster{
    public:
        Mushroom(glm::vec2 position,Way way) : Monster(2,RESOURCE_DIR"/image/character/monster/mushroom/mushroom_walk") {
            this->SetWay(way);
            this->SetZIndex(100);
            this->SetPosition(position);
        };
        void Hurt() override;
        void Action() override;

    private:
        std::shared_ptr<AnimationObject> walk = std::make_shared<AnimationObject>(2,RESOURCE_DIR "/image/character/monster/mushroom/mushroom_walk");
        std::shared_ptr<StillObject> die = std::make_shared<StillObject>(RESOURCE_DIR "/image/character/monster/mushroom/mushroom_die.png");
};
#endif //MUSHROOM_HPP
