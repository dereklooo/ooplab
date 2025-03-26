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
            m_Background->SetSize({1.5,1.5});
            m_Background->SetPivot({-3584,240});
            m_Background->SetPosition({-640,360});

            MapManerger = std::make_shared<MapManager>(m_Background->GetPosition());
            ScenceManager = MapManerger->SetBlock(LuckyBlockPosition,RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock.png");
            for (auto object : ScenceManager) {
                std::cout<<object->GetPosition().x << " "<<object->GetPosition().y<<std::endl;
            }
        }
        void condition() override {
            switch (Condition_num) {
                case 1:
                    if (m_Background->GetPosition().x <= 4700) {
                        Monsters.push_back(std::make_shared<Mushroom>(2,
                        RESOURCE_DIR "/image/character/monster/mushroom/mushroom_walk",
                        glm::vec2{600,-247}));
                        for (auto monster : Monsters) {
                            m_renderer->AddChild(monster);
                        }
                        Condition_num += 1;
                    }
                        break;
                case 2:
                    break;

            }
        }
      private:
            std::vector<glm::vec2> LuckyBlockPosition = {{16.5,-9.5},{22.5,-5.5},{21.5,-9.5},{23.5,-9.5}};


};
#endif //LEVEL1_HPP