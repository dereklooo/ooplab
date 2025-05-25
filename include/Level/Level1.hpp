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
        Level1() : Level() {
            m_Background = std::make_shared<Map>(RESOURCE_DIR "/image/Background/Level1/level_1.png",glm::vec2(-3584,480),glm::vec2(-640,360));

            m_ManagerManager = std::make_shared<ManagerManager>(Items,Blocks,Monsters,FireBalls,m_Mario,m_renderer,m_Background);

            m_ManagerManager->SetFloor(FloorBlock, FloorSize);

            m_ManagerManager->SetBlock(LuckyBlockPosition, BlockType::Lucky);
            m_ManagerManager->SetBlock(OriginBlock, BlockType::Original);
            m_ManagerManager->SetBlock(FootBlock, BlockType::Foot);
            m_ManagerManager->SetBlock(Pipe_64_64, BlockType::Pipe_64_64);
            m_ManagerManager->SetBlock(Pipe_64_96, BlockType::Pipe_64_96);
            m_ManagerManager->SetBlock(Pipe_64_128, BlockType::Pipe_64_128);
            m_ManagerManager->SetBlock(BlueFloorBlock,BlockType::Blue_Floor);
            m_ManagerManager->SetBlock(BlueOriginalBlock, BlockType::Blue_Original);
            //m_ManagerManager->SetBlock(AirBlock, BlockType::Air);
            m_ManagerManager->SetBlock(HorizontalPipe_64_64,BlockType::HorizontalPipe_64_64);
            m_ManagerManager->SetBlock(LongPipe,BlockType::LongPipe);

            m_ManagerManager->SetItem(Item_Mushroom, ItemType::Item_Mushroom);
            m_ManagerManager->SetItem(Item_FireFlower, ItemType::Item_FireFlower);
            m_ManagerManager->SetItem(Item_Coin, ItemType::Item_Coin);
            m_ManagerManager->SetItem(Item_Star,ItemType::Item_Star);
            m_ManagerManager->SetItem(Item_OutSideCoin, ItemType::Item_OutSideCoin);

            m_ManagerManager->SetBlock(Flag,BlockType::flag);
            m_ManagerManager->SetBlock(FlagBall,BlockType::flagball);
            m_ManagerManager->SetBlock(FlagPole,BlockType::flagpole);

            m_ManagerManager->SetAnotherMap(AnotherMapPos,NextPipePos);

        }

        void Update() override {

            if(m_Mario->GetPosition().y <= -400 && m_Mario->GetAnimating() == false) {
                this->GameOver = true;
                return;
            }
            std::vector<std::shared_ptr<Monster>> _temp;
            switch (Condition_num) {
                case 1:
                    if (m_Background->GetPosition().x <= -600 && m_Background->GetPosition().x >= -650) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(650,-220),Left));
                        _temp.push_back(std::make_shared<Turtle>(glm::vec2(600,-220),Left)); // 測試用之後記得刪掉
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }
                    break;
                case 2:
                    if (m_Background->GetPosition().x <= -1050 && m_Background->GetPosition().x >= -1100) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(1000,-220),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }
                    break;
                case 3:
                    if (m_Background->GetPosition().x <= -1630 && m_Background->GetPosition().x >= -1680) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(900,-220),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(960,-220),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }
                    break;
                case 4:
                    if (m_Background->GetPosition().x <= -3000 && m_Background->GetPosition().x >= -3050) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(1000,140),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(1050,140),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }
                        break;
                case 5:
                    if (m_Background->GetPosition().x <= -3900 && m_Background->GetPosition().x >= -3950) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(700,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(775,-247),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }
                    break;
                case 6:
                    if(m_Background->GetPosition().x <= -4600 && m_Background->GetPosition().x >= -4650) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Turtle>(glm::vec2(625,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(700,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(775,-247),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }
                    break;
                case 7:
                    if(m_Background->GetPosition().x <= -5300 && m_Background->GetPosition().x >= -5350) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(700,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(750,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(900,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(950,-247),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }
                    break;
                case 8:
                    if(m_Background->GetPosition().x <= -7400 && m_Background->GetPosition().x >= -7450) {
                        _temp.clear();
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(600,-247),Left));
                        _temp.push_back(std::make_shared<Mushroom>(glm::vec2(650,-247),Left));
                        m_ManagerManager->AddMonster(_temp,m_renderer);
                        Condition_num += 1;
                    }
                break;
                default:
                    break;;
            }
        }
      private:
    std::vector<glm::vec2> AirBlock = {{70.5, -18.5}, {70.5, -19.5}, {70.5, -20.5}, {70.5, -21.5}, {70.5, -22.5},
        {70.5, -23.5}, {70.5, -24.5}, {70.5, -25.5}, {70.5, -26.5}, {70.5, -27.5},
        {70.5, -28.5},};
        std::vector<glm::vec2> LongPipe = {{71,-23.5}};
       std::vector<glm::vec2> LuckyBlockPosition = {{16.5,-9.5},{22.5,-5.5},{21.5,-9.5},{23.5,-9.5},{78.5,-9.5},{94.5,-5.5},{106.5,-9.5},{109.5,-9.5},{109.5,-5.5},{112.5,-9.5},{129.5,-5.5},{130.5,-5.5},{170.5,-9.5}};
       std::vector<glm::vec2>OriginBlock = {{20.5,-9.5} , {22.5,-9.5} , {24.5,-9.5} , {77.5,-9.5} , {79.5,-9.5} , {80.5,-5.5} , {81.5,-5.5} , {82.5,-5.5} , {83.5,-5.5} , {84.5,-5.5} , {85.5,-5.5} , {86.5,-5.5} , {87.5,-5.5} , {91.5,-5.5} ,
       {92.5,-5.5} , {93.5,-5.5} , {100.5,-9.5} , {118.5,-9.5} , {121.5 , -5.5} , {122.5 , -5.5} , {123.5,-5.5},{128.5 , -5.5} ,{129.5,-9.5},{130.5,-9.5}, {131.5 , -5.5} , {168.5,-9.5},{169.5 , -9.5} , {171.5 , -9.5}   ,{101.5,-9.5}};
       std::vector<glm::vec2> FootBlock = {{134.5, -12.5},{135.5, -12.5},{135.5, -11.5},{136.5, -12.5},{136.5, -11.5},{136.5, -10.5},{137.5, -12.5},{137.5, -11.5},{137.5, -10.5},{137.5, -9.5},{143.5, -12.5}, {142.5, -12.5}, {142.5, -11.5}, {141.5, -12.5}, {141.5, -11.5}, {141.5, -10.5}, {140.5, -12.5}, {140.5, -11.5}, {140.5, -10.5}, {140.5, -9.5},
    {148.5, -12.5}, {149.5, -12.5}, {150.5, -12.5}, {151.5, -12.5}, {152.5, -12.5}, {149.5, -11.5}, {150.5, -11.5}, {151.5, -11.5}, {152.5, -11.5}, {150.5, -10.5}, {151.5, -10.5}, {152.5, -10.5}, {151.5, -9.5}, {152.5, -9.5},{158.5, -12.5}, {157.5, -12.5}, {156.5, -12.5}, {155.5, -12.5}, {157.5, -11.5}, {156.5, -11.5}, {155.5, -11.5}, {156.5, -10.5}, {155.5, -10.5}, {155.5, -9.5},
    {181.5, -12.5}, {182.5, -12.5}, {183.5, -12.5}, {184.5, -12.5}, {185.5, -12.5}, {186.5, -12.5}, {187.5, -12.5}, {188.5, -12.5}, {189.5, -12.5}, {182.5, -11.5}, {183.5, -11.5}, {184.5, -11.5}, {185.5, -11.5}, {186.5, -11.5}, {187.5, -11.5}, {188.5, -11.5}, {189.5, -11.5}, {183.5, -10.5}, {184.5, -10.5}, {185.5, -10.5}, {186.5, -10.5}, {187.5, -10.5}, {188.5, -10.5}, {189.5, -10.5}, {184.5, -9.5}, {185.5, -9.5}, {186.5, -9.5}, {187.5, -9.5}, {188.5, -9.5}, {189.5, -9.5}, {185.5, -8.5}, {186.5, -8.5}, {187.5, -8.5}, {188.5, -8.5}, {189.5, -8.5}, {186.5, -7.5}, {187.5, -7.5}, {188.5, -7.5}, {189.5, -7.5}, {187.5, -6.5}, {188.5, -6.5}, {189.5, -6.5}, {188.5, -5.5}, {189.5, -5.5}, {189.5, -4.5}
       ,{198.5, -12.5}};
        std::vector<glm::vec2> FloorBlock = {{34.5,-14},{78.5,-14},{120.5,-14},{189.0f,-14}};
        std::vector<glm::vec2> FloorSize = {{69.0f,2.0f},{15.0f,2.0f},{64.0f,2.0f},{69.0f,2.0f}};

        std::vector<glm::vec2> Pipe_64_64 = {{29,-12},{164,-12},{180,-12}};
        std::vector<glm::vec2> Pipe_64_96 = {{39,-11.5}};
        std::vector<glm::vec2> Pipe_64_128 = {{47,-11},{58,-11}};
        std::vector<glm::vec2> HorizontalPipe_64_64 = {{69,-28}};

        std::vector<glm::vec2> BlueOriginalBlock = {
            {55.5, -17.5}, {55.5, -18.5}, {55.5, -19.5}, {55.5, -20.5}, {55.5, -21.5}, {55.5, -22.5},
            {55.5, -23.5}, {55.5, -24.5}, {55.5, -25.5}, {55.5, -26.5}, {55.5, -27.5},{55.5,-28.5},
            {59.5, -17.5}, {60.5, -17.5}, {61.5, -17.5}, {62.5, -17.5}, {63.5, -17.5}, {64.5, -17.5},
            {65.5, -17.5}, {59.5, -26.5}, {60.5, -26.5}, {61.5, -26.5}, {62.5, -26.5}, {63.5, -26.5}, {64.5, -26.5}, {65.5, -26.5},
            {59.5, -27.5}, {60.5, -27.5}, {61.5, -27.5}, {62.5, -27.5}, {63.5, -27.5}, {64.5, -27.5}, {65.5, -27.5},
            {59.5, -28.5}, {60.5, -28.5}, {61.5, -28.5}, {62.5, -28.5}, {63.5, -28.5}, {64.5, -28.5}, {65.5, -28.5},
            {72.5, -28.5}, {72.5, -27.5}, {72.5, -26.5}, {72.5, -25.5}, {72.5, -24.5},
            {72.5, -23.5}, {72.5, -22.5}, {72.5, -21.5}, {72.5, -20.5}, {72.5, -19.5},
            {72.5, -18.5}, {72.5, -17.5}
        };

        std::vector<glm::vec2> BlueFloorBlock = {
            {55.5, -30.5}, {56.5, -30.5}, {57.5, -30.5}, {58.5, -30.5}, {59.5, -30.5}, {60.5, -30.5},
            {61.5, -30.5}, {62.5, -30.5}, {63.5, -30.5}, {64.5, -30.5}, {65.5, -30.5}, {66.5, -30.5},
            {67.5, -30.5}, {68.5, -30.5}, {69.5, -30.5}, {70.5, -30.5}, {71.5, -30.5},{72.5,-30.5},
            {55.5, -29.5}, {56.5, -29.5}, {57.5, -29.5}, {58.5, -29.5}, {59.5, -29.5}, {60.5, -29.5},
            {61.5, -29.5}, {62.5, -29.5}, {63.5, -29.5}, {64.5, -29.5}, {65.5, -29.5}, {66.5, -29.5},
            {67.5, -29.5}, {68.5, -29.5}, {69.5, -29.5}, {70.5, -29.5}, {71.5, -29.5},{72.5,-29.5},
            {55.5, -31.5}, {56.5, -31.5}, {57.5, -31.5}, {58.5, -31.5}, {59.5, -31.5},
           {60.5, -31.5}, {61.5, -31.5}, {62.5, -31.5}, {63.5, -31.5}, {64.5, -31.5},
           {65.5, -31.5}, {66.5, -31.5}, {67.5, -31.5}, {68.5, -31.5}, {69.5, -31.5},
           {70.5, -31.5}, {71.5, -31.5}, {72.5, -31.5}
        };

        std::vector<glm::vec2> Item_Mushroom = {{21.5f,-9.5f},{78.5f,-9.5f}};
        std::vector<glm::vec2> Item_FireFlower = {{109.5f,-5.5f}};
        std::vector<glm::vec2> Item_Coin = {{16.5f,-9.5},{22.5,-5.5f},{23.5f,-9.5f},{94.5f,-5.5f},{94.5f,-9.5f},{106.5f,-9.5f},{109.5f,-9.5f},{112.5f,-9.5f},{129.5f,-5.5f},{130.5f,-5.5f},{170.5f,-9.5f}};
        std::vector<glm::vec2> Item_Star = {{101.5,-9.5}};
        std::vector<glm::vec2> Item_OutSideCoin = {
        {59.5, -20.5}, {60.5, -20.5}, {61.5, -20.5}, {62.5, -20.5}, {63.5, -20.5}, {64.5, -20.5}, {65.5, -20.5},
        {59.5, -21.5}, {60.5, -21.5}, {61.5, -21.5}, {62.5, -21.5}, {63.5, -21.5}, {64.5, -21.5}, {65.5, -21.5},
        {59.5, -22.5}, {60.5, -22.5}, {61.5, -22.5}, {62.5, -22.5}, {63.5, -22.5}, {64.5, -22.5}, {65.5, -22.5},
        {59.5, -23.5}, {60.5, -23.5}, {61.5, -23.5}, {62.5, -23.5}, {63.5, -23.5}, {64.5, -23.5}, {65.5, -23.5},
        {59.5, -24.5}, {60.5, -24.5}, {61.5, -24.5}, {62.5, -24.5}, {63.5, -24.5}, {64.5, -24.5}, {65.5, -24.5},
        {59.5, -25.5}, {60.5, -25.5}, {61.5, -25.5}, {62.5, -25.5}, {63.5, -25.5}, {64.5, -25.5}, {65.5, -25.5}};

        std::vector<glm::vec2> Flag = {{198, -2.5}};
        std::vector<glm::vec2> FlagBall = {{198.5, -1.5}};
        std::vector<glm::vec2> FlagPole = {{198.5, -11.5},{198.5, -10.5},{198.5, -9.5},{198.5, -8.5},{198.5, -7.5},{198.5, -6.5},{198.5, -5.5},{198.5, -4.5},{198.5, -3.5},{198.5, -2.5}};
        std::vector<glm::vec2> AnotherMapPos = {{58,-11},{69,-28}};

        std::vector<glm::vec2> NextPipePos = {{0,0},{180,-12}};
};
#endif //LEVEL1_HPP