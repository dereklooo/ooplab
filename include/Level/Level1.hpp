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

            Map_Manager = std::make_shared<MapManager>(m_Background->GetPosition(),m_Background->GetScaledSize());

            Map_Manager->SetFloor(SceneManager,FloorBlock,-13.5);
            Map_Manager->SetBlock(SceneManager,LuckyBlockPosition,BlockType::luckyBlock);
            Map_Manager->SetBlock(SceneManager,OriginBlock,BlockType::originalBlock);
            Map_Manager->SetBlock(SceneManager,FootBlock,BlockType::footBlock);
            Map_Manager->SetBlock(SceneManager,Pipe_64_64,BlockType::pipe_64_64);
            Map_Manager->SetBlock(SceneManager,Pipe_64_96,BlockType::pipe_64_96);
            Map_Manager->SetBlock(SceneManager,Pipe_64_128,BlockType::pipe_64_128);

            Gravity_Manager = std::make_shared<GravityManager>(m_MariO,Monsters,SceneManager);
        }
        void condition() override {
            std::vector<std::shared_ptr<Monster>> _temp;
            switch (Condition_num) {
                case 1:
                    if (m_Background->GetPosition().x <= -600) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(600,-245),Left));
                        MapManager::AddMonster(_temp,m_renderer,Monsters);
                        Condition_num += 1;
                    }
                    break;
                case 2:
                    if (m_Background->GetPosition().x <= -1050) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(1000,-247),Left));
                        MapManager::AddMonster(_temp,m_renderer,Monsters);
                        Condition_num += 1;
                    }
                    break;
                case 3:
                    if (m_Background->GetPosition().x <= -1630) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(900,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(960,-247),Left));
                        MapManager::AddMonster(_temp,m_renderer,Monsters);
                        Condition_num += 1;
                    }
                    break;
                case 4:
                    if (m_Background->GetPosition().x <= -3000) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(1000,140),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(1050,140),Left));
                        MapManager::AddMonster(_temp,m_renderer,Monsters);
                        Condition_num += 1;
                    }
                        break;
                case 5:
                    if (m_Background->GetPosition().x <= -3600) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(1000,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(1050,-247),Left));
                        MapManager::AddMonster(_temp,m_renderer,Monsters);
                        Condition_num += 1;
                    }
                    break;
                default:
                    break;;
            }
        }
      private:
       std::vector<glm::vec2> LuckyBlockPosition = {{16.5,-9.5},{22.5,-5.5},{21.5,-9.5},{23.5,-9.5},{78.5,-9.5},{94.5,-5.5},{106.5,-9.5},{109.5,-9.5},{109.5,-5.5},{112.5,-9.5},{129.5,-5.5},{130.5,-5.5},{170.5,-9.5}};std::vector<glm::vec2> OriginBlock = {{20.5,-9.5} , {22.5,-9.5} , {24.5,-9.5} , {77.5,-9.5} , {79.5,-9.5} , {80.5,-5.5} , {81.5,-5.5} , {82.5,-5.5} , {83.5,-5.5} , {84.5,-5.5} , {85.5,-5.5} , {86.5,-5.5} , {87.5,-5.5} , {91.5,-5.5} ,
       {92.5,-5.5} , {93.5,-5.5} , {100.5,-9.5} , {118.5,-9.5} , {121.5 , -5.5} , {122.5 , -5.5} , {128.5 , -5.5} , {131.5 , -5.5} , {169.5 , -9.5} , {170.5 , -9.5} , {172.5 , -9.5}};
       std::vector<glm::vec2> FootBlock = {{134.5, -12.5},{135.5, -12.5},{135.5, -11.5},{136.5, -12.5},{136.5, -11.5},{136.5, -10.5},{137.5, -12.5},{137.5, -11.5},{137.5, -10.5},{137.5, -9.5},{143.5, -12.5}, {142.5, -12.5}, {142.5, -11.5}, {141.5, -12.5}, {141.5, -11.5}, {141.5, -10.5}, {140.5, -12.5}, {140.5, -11.5}, {140.5, -10.5}, {140.5, -9.5},
    {148.5, -12.5}, {149.5, -12.5}, {150.5, -12.5}, {151.5, -12.5}, {152.5, -12.5}, {149.5, -11.5}, {150.5, -11.5}, {151.5, -11.5}, {152.5, -11.5}, {150.5, -10.5}, {151.5, -10.5}, {152.5, -10.5}, {151.5, -9.5}, {152.5, -9.5},{158.5, -12.5}, {157.5, -12.5}, {156.5, -12.5}, {155.5, -12.5}, {157.5, -11.5}, {156.5, -11.5}, {155.5, -11.5}, {156.5, -10.5}, {155.5, -10.5}, {155.5, -9.5},
    {181.5, -12.5}, {182.5, -12.5}, {183.5, -12.5}, {184.5, -12.5}, {185.5, -12.5}, {186.5, -12.5}, {187.5, -12.5}, {188.5, -12.5}, {189.5, -12.5}, {182.5, -11.5}, {183.5, -11.5}, {184.5, -11.5}, {185.5, -11.5}, {186.5, -11.5}, {187.5, -11.5}, {188.5, -11.5}, {189.5, -11.5}, {183.5, -10.5}, {184.5, -10.5}, {185.5, -10.5}, {186.5, -10.5}, {187.5, -10.5}, {188.5, -10.5}, {189.5, -10.5}, {184.5, -9.5}, {185.5, -9.5}, {186.5, -9.5}, {187.5, -9.5}, {188.5, -9.5}, {189.5, -9.5}, {185.5, -8.5}, {186.5, -8.5}, {187.5, -8.5}, {188.5, -8.5}, {189.5, -8.5}, {186.5, -7.5}, {187.5, -7.5}, {188.5, -7.5}, {189.5, -7.5}, {187.5, -6.5}, {188.5, -6.5}, {189.5, -6.5}, {188.5, -5.5}, {189.5, -5.5}, {189.5, -4.5}};
       std::vector<float> FloorBlock = {69.5f, 70.5f , 86.5f , 87.5f , 88.5f , 153.5f ,154.5f};
       std::vector<glm::vec2> Pipe_64_64 = {{29,-16},{164,-12},{180,-12}};
       std::vector<glm::vec2> Pipe_64_96 = {{39,-11.5}};
       std::vector<glm::vec2> Pipe_64_128 = {{47,-10.5},{58,-10.5}};
};
#endif //LEVEL1_HPP