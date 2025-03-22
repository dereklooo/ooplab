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
            m_Background->SetSize({2.92,3.3});
        };
        void condition() override {
            switch (Condition_num) {
                case 1:
                    if (m_Background->GetPosition().x == 4700) {
                        Monsters.push_back(std::make_shared<Mushroom>(2,
                        RESOURCE_DIR "/image/character/monster/mushroom/mushroom_walk",
                        glm::vec2{600,-275}));
                    }
                        for (auto monster : Monsters) {
                            m_renderer->AddChild(monster);
                        }
                        Condition_num += 1;
                        break;
                case 2:
                    break;

            }
        }

};
#endif //LEVEL1_HPP