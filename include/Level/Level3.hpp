//
// Created by benson on 2025/3/14.
//

#ifndef LEVEL3_HPP
#define LEVEL3_HPP
#include "Level.hpp"
#include "Monsters/Mushroom.hpp"
#include "Monsters/Turtle.hpp"
#include "Monsters/Red_turtle.hpp"
#include "Monsters/Fly_turtle.hpp"
class Level3 : public Level {
public:
    Level3() : Level() {
        m_Background = std::make_shared<Map>(RESOURCE_DIR"/image/Background/Level3/level_3.png",glm::vec2(-2816,240),glm::vec2(-640,360));
        //m_Background = std::make_shared<Map>(RESOURCE_DIR "/image/Background/Level1/level_1.png",glm::vec2(-3584,480),glm::vec2(-640,360));
            m_ManagerManager = std::make_shared<ManagerManager>(Items,Blocks,Monsters,FireBalls,m_Mario,m_renderer,m_Background);

        m_ManagerManager->SetBlock(LuckyBlockPosition, BlockType::Lucky);
        m_ManagerManager->SetBlock(GrassFloorLeft, BlockType::GrassFloorLeft);
        m_ManagerManager->SetBlock(GrassFloorMid, BlockType::GrassFloorMid);
        m_ManagerManager->SetBlock(GrassFloorRight, BlockType::GrassFloorRight);
        m_ManagerManager->SetBlock(AirBlock, BlockType::Air);
        m_ManagerManager->SetBlock(Flag,BlockType::flag);
        m_ManagerManager->SetBlock(FlagBall,BlockType::flagball);
        m_ManagerManager->SetBlock(FlagPole,BlockType::flagpole);
        //m_ManagerManager->SetBlock(elevator,BlockType::HorizontalElevator);
        m_ManagerManager->SetItem(Item_OutSideCoin, ItemType::Item_OutSideCoin);
        m_ManagerManager->SetItem(Item_Mushroom, ItemType::Item_Mushroom);
        m_ManagerManager->SetElevator({56.5,-4.5},240,Way::up);
        m_ManagerManager->SetElevator({88.5,-8.5},48*3,Way::Left);
        m_ManagerManager->SetElevator({94.5,-9.5},48*3,Way::Right);
        m_ManagerManager->SetElevator({132.5,-6.5},48*5,Way::Right);
        //m_Background->SetPosition({m_Mario->GetPosition().x,m_Mario->GetPosition().y});
        }

        void Update() override {
        //m_Mario->SetPosition(m_Background->GetPosition());
            if(m_Mario->GetPosition().y <= -400 && m_Mario->GetAnimating() == false) {
                this->GameOver = true;
                return;
            }
            std::vector<std::shared_ptr<Monster>> _temp;

            switch (Condition_num) {
                case 1:
                    if (m_Background->GetPosition().x <= -645 && m_Background->GetPosition().x >= -708 && !m_Mario->GetAnimating()) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<RedTurtle>(glm::vec2(700,140),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }

                    break;
                case 2:
                if (m_Background->GetPosition().x <= -1330 && m_Background->GetPosition().x >= -1350 && !m_Mario->GetAnimating()) {
                    _temp.clear();
                    _temp.push_back(std::make_shared<Mushroom>(glm::vec2(700,190),Left));
                    _temp.push_back(std::make_shared<Mushroom>(glm::vec2(760,190),Left));
                    m_ManagerManager->AddMonster(_temp,m_renderer);
                    Condition_num += 1;
                }

                break;
                case 3:
                    if (m_Background->GetPosition().x <= -2870 && m_Background->GetPosition().x >= -2900 && !m_Mario->GetAnimating()) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<FlyTurtle>(glm::vec2(700,140),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(900,95),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }

                break;

                case 4:
                    if (m_Background->GetPosition().x <= -4500 && m_Background->GetPosition().x >= -4550 && !m_Mario->GetAnimating()) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<RedTurtle>(glm::vec2(700,45),Left));
                        _temp.push_back(std::make_shared<FlyTurtle>(glm::vec2(1000,140),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }

                break;
                case 5:
                    if (m_Background->GetPosition().x <= -5700 && m_Background->GetPosition().x >= -5750 && !m_Mario->GetAnimating()) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<RedTurtle>(glm::vec2(700,-220),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }

                break;
                default:
                    break;
            }
        }
      private:
    std::vector<glm::vec2> AirBlock = {{142.5,-5.5} , {143.5,-5.5} ,
{142.5,-6.5} , {143.5,-6.5} ,
{140.5,-7.5} , {141.5,-7.5} , {142.5,-7.5} , {143.5,-7.5} ,
{140.5,-8.5} , {143.5,-8.5} ,
{138.5,-9.5} , {139.5,-9.5} , {140.5,-9.5} , {143.5,-9.5} ,
{138.5,-10.5} , {143.5,-10.5} ,
{138.5,-11.5} , {143.5,-11.5} ,
{138.5,-12.5} , {143.5,-12.5} ,
{0.5,-13.5} , {1.5,-13.5} , {2.5,-13.5} , {3.5,-13.5} , {4.5,-13.5} , {5.5,-13.5} , {6.5,-13.5} , {7.5,-13.5} , {8.5,-13.5} , {9.5,-13.5} , {10.5,-13.5} , {11.5,-13.5} , {12.5,-13.5} , {13.5,-13.5} , {14.5,-13.5} , {15.5,-13.5} , {129.5,-13.5} , {130.5,-13.5} , {131.5,-13.5} , {132.5,-13.5} , {133.5,-13.5} , {134.5,-13.5} , {135.5,-13.5} , {136.5,-13.5} , {137.5,-13.5} , {138.5,-13.5} , {139.5,-13.5} , {140.5,-13.5} , {141.5,-13.5} , {142.5,-13.5} , {143.5,-13.5} , {144.5,-13.5} , {145.5,-13.5} , {146.5,-13.5} , {147.5,-13.5} , {148.5,-13.5} , {149.5,-13.5} , {150.5,-13.5} , {151.5,-13.5} , {152.5,-13.5} , {153.5,-13.5} , {154.5,-13.5} , {155.5,-13.5} , {156.5,-13.5} , {157.5,-13.5} , {158.5,-13.5} , {159.5,-13.5} , {160.5,-13.5} , {161.5,-13.5} , {162.5,-13.5} , {163.5,-13.5} ,
{15.5,-14.5} , {129.5,-14.5}};

    //std::vector<float> FloorBlock = {-0.5, 1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5,11.5,12.5,13.5,14.5,15.5,129.5,130.5,131.5,132.5,133.5,134.5,135.5,136.5,137.5,138.5,139.5,140.5,141.5,142.5,143.5,144.5,145.5,146.5,147.5,148.5,149.5,150.5,151.5,152.5,153.5,154.5,155.5,156.5,157.5,158.5,159.5,160.5,161.5,162.5,163.5};
    std::vector<glm::vec2> FootBlock = {{142.5,-5.5} , {143.5,-5.5} ,
{142.5,-6.5} , {143.5,-6.5} ,
{140.5,-7.5} , {141.5,-7.5} , {142.5,-7.5} , {143.5,-7.5} ,
{140.5,-8.5} , {141.5,-8.5} , {142.5,-8.5} , {143.5,-8.5} ,
{138.5,-9.5} , {139.5,-9.5} , {140.5,-9.5} , {141.5,-9.5} , {142.5,-9.5} , {143.5,-9.5} ,
{138.5,-10.5} , {139.5,-10.5} , {140.5,-10.5} , {141.5,-10.5} , {142.5,-10.5} , {143.5,-10.5} ,
{138.5,-11.5} , {139.5,-11.5} , {140.5,-11.5} , {141.5,-11.5} , {142.5,-11.5} , {143.5,-11.5} ,
{138.5,-12.5} , {139.5,-12.5} , {140.5,-12.5} , {141.5,-12.5} , {142.5,-12.5} , {143.5,-12.5}, {152.5,-12.5}};
    std::vector<glm::vec2> GrassFloorLeft = {{40.5,-4.5} ,
{26.5,-5.5} , {60.5,-5.5} ,
{76.5,-6.5} ,
{104.5,-7.5} ,
{35.5,-8.5} ,
{24.5,-9.5} , {70.5,-9.5} , {116.5,-9.5} , {122.5,-9.5} ,
{98.5,-11.5} ,
{18.5,-12.5} , {32.5,-12.5} ,
{50.5,-13.5} , {59.5,-13.5} , {65.5,-13.5} , {113.5,-13.5}};
    std::vector<glm::vec2> GrassFloorMid ={{41.5,-4.5} , {42.5,-4.5} , {43.5,-4.5} , {44.5,-4.5} , {45.5,-4.5} ,
{27.5,-5.5} , {28.5,-5.5} , {29.5,-5.5} , {61.5,-5.5} , {62.5,-5.5} ,
{77.5,-6.5} , {78.5,-6.5} , {79.5,-6.5} , {80.5,-6.5} ,
{105.5,-7.5} , {106.5,-7.5} , {107.5,-7.5} , {108.5,-7.5} , {109.5,-7.5} , {110.5,-7.5} ,
{36.5,-8.5} , {37.5,-8.5} , {38.5,-8.5} ,
{25.5,-9.5} , {26.5,-9.5} , {27.5,-9.5} , {28.5,-9.5} , {29.5,-9.5} , {30.5,-9.5} , {71.5,-9.5} , {117.5,-9.5} , {118.5,-9.5} , {123.5,-9.5} , {124.5,-9.5} ,
{99.5,-11.5} , {100.5,-11.5} ,
{19.5,-12.5} , {20.5,-12.5} , {33.5,-12.5} ,
{51.5,-13.5} , {52.5,-13.5} , {60.5,-13.5} , {61.5,-13.5} , {62.5,-13.5} , {66.5,-13.5} , {67.5,-13.5} , {68.5,-13.5} , {114.5,-13.5}};
    std::vector<glm::vec2> GrassFloorRight ={{46.5,-4.5} ,
{30.5,-5.5} , {63.5,-5.5} ,
{81.5,-6.5} ,
{111.5,-7.5} ,
{39.5,-8.5} ,
{31.5,-9.5} , {72.5,-9.5} , {119.5,-9.5} , {125.5,-9.5} ,
{101.5,-11.5} ,
{21.5,-12.5} , {34.5,-12.5} ,
{53.5,-13.5} , {63.5,-13.5} , {69.5,-13.5} , {115.5,-13.5}};

    std::vector<glm::vec2> TreeWall ={{41.5,-5.5} , {45.5,-5.5} ,
{27.5,-6.5} , {29.5,-6.5} , {41.5,-6.5} , {45.5,-6.5} , {61.5,-6.5} , {62.5,-6.5} ,
{27.5,-7.5} , {29.5,-7.5} , {41.5,-7.5} , {45.5,-7.5} , {61.5,-7.5} , {62.5,-7.5} , {77.5,-7.5} , {80.5,-7.5} ,
{27.5,-8.5} , {29.5,-8.5} , {41.5,-8.5} , {45.5,-8.5} , {61.5,-8.5} , {62.5,-8.5} , {77.5,-8.5} , {80.5,-8.5} , {105.5,-8.5} , {110.5,-8.5} ,
{36.5,-9.5} , {38.5,-9.5} , {41.5,-9.5} , {45.5,-9.5} , {61.5,-9.5} , {62.5,-9.5} , {77.5,-9.5} , {80.5,-9.5} , {105.5,-9.5} , {110.5,-9.5} ,
{25.5,-10.5} , {30.5,-10.5} , {36.5,-10.5} , {38.5,-10.5} , {41.5,-10.5} , {45.5,-10.5} , {61.5,-10.5} , {62.5,-10.5} , {71.5,-10.5} , {77.5,-10.5} , {80.5,-10.5} , {105.5,-10.5} , {110.5,-10.5} , {117.5,-10.5} , {118.5,-10.5} , {123.5,-10.5} , {124.5,-10.5} ,
{25.5,-11.5} , {30.5,-11.5} , {36.5,-11.5} , {38.5,-11.5} , {41.5,-11.5} , {45.5,-11.5} , {61.5,-11.5} , {62.5,-11.5} , {71.5,-11.5} , {77.5,-11.5} , {80.5,-11.5} , {105.5,-11.5} , {110.5,-11.5} , {117.5,-11.5} , {118.5,-11.5} , {123.5,-11.5} , {124.5,-11.5} ,
{25.5,-12.5} , {30.5,-12.5} , {36.5,-12.5} , {38.5,-12.5} , {41.5,-12.5} , {45.5,-12.5} , {61.5,-12.5} , {62.5,-12.5} , {71.5,-12.5} , {77.5,-12.5} , {80.5,-12.5} , {99.5,-12.5} , {100.5,-12.5} , {105.5,-12.5} , {110.5,-12.5} , {117.5,-12.5} , {118.5,-12.5} , {123.5,-12.5} , {124.5,-12.5} ,
{19.5,-13.5} , {20.5,-13.5} , {25.5,-13.5} , {30.5,-13.5} , {33.5,-13.5} , {36.5,-13.5} , {38.5,-13.5} , {41.5,-13.5} , {45.5,-13.5} , {71.5,-13.5} , {77.5,-13.5} , {80.5,-13.5} , {99.5,-13.5} , {100.5,-13.5} , {105.5,-13.5} , {110.5,-13.5} , {117.5,-13.5} , {118.5,-13.5} , {123.5,-13.5} , {124.5,-13.5} ,
{19.5,-14.5} , {20.5,-14.5} , {25.5,-14.5} , {30.5,-14.5} , {33.5,-14.5} , {36.5,-14.5} , {38.5,-14.5} , {41.5,-14.5} , {45.5,-14.5} , {51.5,-14.5} , {52.5,-14.5} , {60.5,-14.5} , {62.5,-14.5} , {66.5,-14.5} , {68.5,-14.5} , {71.5,-14.5} , {77.5,-14.5} , {80.5,-14.5} , {99.5,-14.5} , {100.5,-14.5} , {105.5,-14.5} , {110.5,-14.5} , {114.5,-14.5} , {117.5,-14.5} , {118.5,-14.5} , {123.5,-14.5} , {124.5,-14.5}};
    std::vector<glm::vec2> FlagPole ={{152.5,-3.5} , {152.5,-4.5} , {152.5,-5.5} , {152.5,-6.5} , {152.5,-7.5} , {152.5,-8.5} , {152.5,-9.5} , {152.5,-10.5} , {152.5,-11.5}};
    std::vector<glm::vec2> FlagBall = {{152.5,-2.5}};
    std::vector<glm::vec2> Flag = {{152,-3.5}};

    std::vector<glm::vec2> Item_OutSideCoin ={{37.5,-2.5} , {38.5,-2.5} ,
{27.5,-4.5} , {28.5,-4.5} , {29.5,-4.5} , {60.5,-4.5} , {61.5,-4.5} , {62.5,-4.5} , {63.5,-4.5} , {93.5,-4.5} , {94.5,-4.5} , {97.5,-4.5} , {98.5,-4.5} ,
{85.5,-5.5} , {86.5,-5.5} , {120.5,-5.5} , {121.5,-5.5} ,
{50.5,-6.5} , {51.5,-6.5} ,
{33.5,-11.5} ,
{113.5,-12.5} , {114.5,-12.5} , {115.5,-12.5} };
    std::vector<glm::vec2> LuckyBlockPosition = {{59.5,-10.5}};
    std::vector<glm::vec2> Item_Mushroom = {{59.5,-10.5}};
    std::vector<glm::vec2> elevator = {{56.5,-7.5},{87.5,-8.5},{95.5,-9.5},{132.5,-6.5}};


};

#endif //LEVEL3_HPP
