//
// Created by benson on 2025/3/14.
//

#ifndef LEVEL1_HPP
#define LEVEL1_HPP
#include "Level.hpp"
#include "Monsters/Mushroom.hpp"
#include "Monsters/Turtle.hpp"
class Level1 : public Level{
      public:
        Level1() {
            m_Background = std::make_shared<StillObject>(RESOURCE_DIR "/image/Background/Level1/level_1.png");
            m_Background->SetSize({0.8,0.8});
            Monsters.push_back(std::make_shared<Mushroom>());
            Monsters.push_back(std::make_shared<Turtle>());
        };
        void condition() {

        }


};
#endif //LEVEL1_HPP