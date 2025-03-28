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

            MapManerger = std::make_shared<MapManager>(m_Background->GetPosition(),m_Background->GetScaledSize());
            MapManerger->SetFloor(SceneManager,FloorBlock,-13.5);
            MapManerger->SetBlock(SceneManager,LuckyBlockPosition,BlockType::luckyBlock);
            MapManerger->SetBlock(SceneManager,OriginBLock,BlockType::originalBlock);
        }
        void condition() override {
            switch (Condition_num) {
                case 1:
                    if (m_Background->GetPosition().x <= 4700) {
                        MapManerger->AddMonster(std::make_shared<Mushroom>(glm::vec2(600,-247),Left),m_renderer,Monsters);
                        Condition_num += 1;
                    }
                    break;
                case 2:
                    if (m_Background->GetPosition().x <= -1050) {
                        Monsters.push_back(std::make_shared<Mushroom>(glm::vec2(1000,-247),Left));
                        for (auto &monster : Monsters) {
                            m_renderer->AddChild(monster);
                        }
                        Condition_num += 1;
                    }
                    break;

            }
        }
      private:
            std::vector<glm::vec2> LuckyBlockPosition = {{16.5,-9.5},{22.5,-5.5},{21.5,-9.5},{23.5,-9.5},{78.5,-9.5},{94.5,-5.5},{106.5,-9.5},{109.5,-9.5},{109.5,-5.5},{112.5,-9.5},{129.5,-5.5},{130.5,-5.5},{170.5,-9.5}};
            std::vector<glm::vec2> OriginBLock = {{20.5,-9.5} , {22.5,-9.5} , {24.5,-9.5} , {77.5,-9.5} , {79.5,-9.5} , {80.5,-5.5} , {81.5,-5.5} , {82.5,-5.5} , {83.5,-5.5} , {84.5,-5.5} , {85.5,-5.5} , {86.5,-5.5} , {87.5,-5.5} , {91.5,-5.5} ,
            {92.5,-5.5} , {93.5,-5.5} , {100.5,-9.5} , {118.5,-9.5} , {121.5 , -5.5} , {122.5 , -5.5} , {128.5 , -5.5} , {131.5 , -5.5} , {169.5 , -9.5} , {170.5 , -9.5} , {172.5 , -9.5}};
            std::vector<float> FloorBlock = {69.5f, 70.5f , 86.5f , 87.5f , 88.5f , 153.5f ,154.5f};
};
#endif //LEVEL1_HPP