//
// Created by Benson on 2025/3/24.
//

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP
#include "Block/OriginalBlock.hpp"
#include "Block/LuckyBlock.hpp"
#include "Block/FootBlock.hpp"
#include "Block/Pipe_64_128.hpp"
#include "Block/Pipe_64_96.hpp"
#include "Block/Pipe_64_64.hpp"

#include "Monsters/Mushroom.hpp"
#include "Monsters/Turtle.hpp"

#include "Mario/Mario.hpp"
#include <iostream>
enum BlockType {
    luckyBlock,
    originalBlock,
    footBlock,
    pipe_64_64,
    pipe_64_96,
    pipe_64_128,
    airBlock,
};
class MapManager {
    public:
        MapManager(const glm::vec2 MapPosition, const glm::vec2 MapSize) {
            this->MapPosition = MapPosition;
            this->MapSize = MapSize;
        }
        void SetFloor(std::vector<std::shared_ptr<SceneObject>>& SceneManager,std::vector<float> &Position,float Floor_y) {
            for(float i = 0.5f ; i <= MapSize.x / 32 ; i++) {
                bool Build = true;
                for(float position : Position) {
                    if(position == i) {
                        Build = false;
                    }
                }
                if(Build) {
                    auto temp = std::make_shared<SceneObject>(RESOURCE_DIR"/image/Background/Level1/Block/AirBlock.png",glm::vec2(MapPosition.x + i * 48 , MapPosition.y + Floor_y * 48));
                    SceneManager.push_back(temp);
                    temp = std::make_shared<SceneObject>(RESOURCE_DIR"/image/Background/Level1/Block/AirBlock.png",glm::vec2(MapPosition.x + i * 48 , MapPosition.y + (Floor_y - 1) * 48));
                    SceneManager.push_back(temp);
                }
            }
        }
        void SetBlock(std::vector<std::shared_ptr<SceneObject>>& SceneManager,std::vector<glm::vec2> &Position,BlockType type) {
            for (const auto position : Position) {
                auto temp = std::shared_ptr<SceneObject>();
                switch(type) {
                    case(luckyBlock) :
                        temp = std::make_shared<LuckyBlock>(glm::vec2(MapPosition.x + position.x * 48 , MapPosition.y + position.y * 48));
                        break;
                    case(originalBlock) :
                        temp = std::make_shared<OriginalBlock>(glm::vec2(MapPosition.x + position.x * 48 , MapPosition.y + position.y * 48));
                        break;
                    case(footBlock) :
                        temp = std::make_shared<FootBlock>(glm::vec2(MapPosition.x + position.x * 48 , MapPosition.y + position.y * 48));
                        break;
                    case(pipe_64_64) :
                        temp = std::make_shared<Pipe64_64>(glm::vec2(MapPosition.x + position.x * 48 , MapPosition.y + position.y * 48));
                        break;

                    case(pipe_64_96) :
                        temp = std::make_shared<Pipe64_96>(glm::vec2(MapPosition.x + position.x * 48 , MapPosition.y + position.y * 48));
                        break;

                    case(pipe_64_128) :
                        temp = std::make_shared<Pipe64_128>(glm::vec2(MapPosition.x + position.x * 48 , MapPosition.y + position.y * 48));
                        break;
                    default:
                        temp = nullptr;
                        break;
                }
                temp->SetZIndex(50);
                temp->SetSize({1.5,1.5});
                SceneManager.push_back(temp);
            }
        }
        void AddMonster(const std::shared_ptr<Monster> &monster,const std::shared_ptr<Util::Renderer> &renderer,std::vector<std::shared_ptr<Monster>> &Monsters) {
            Monsters.push_back(monster);
            for (auto &monster : Monsters) {
                renderer->AddChild(monster);
            }
        }
        static void MonsterCollision(const std::vector<std::shared_ptr<Monster>> &Monsters,const std::vector<std::shared_ptr<SceneObject>> &SceneObjects) {
            for(const auto &Monster : Monsters) {
                for(const auto& SceneObject : SceneObjects) {
                    if(Monster->Collision(SceneObject)) {
                        if(Monster->GetWay() == Way::Left) {
                            Monster->SetWay(Way::Right);
                            Monster->SetSize({1,1});
                        }
                        else {
                            Monster->SetWay(Way::Left);
                            Monster->SetSize({-1,1});
                        }
                    }
                }
            }
        }
        void SceneObjectCollision(const std::vector<std::shared_ptr<Monster>> &Monsters) {

        }
        static void Update(const std::shared_ptr<Mario>& Mario,
            const std::vector<std::shared_ptr<Monster>>& Monsters,
            const std::vector<std::shared_ptr<SceneObject>>& SceneObjects) {

            for(auto &monster : Monsters) {
                if(Mario->Collision(monster)) {
                    if(Mario->GetPosition().y - Mario->GetScaledSize().y / 2 >= monster->GetPosition().y + monster->GetScaledSize().y / 2) {
                        monster->Hurt();
                    }
                    else {
                        Mario->Hurt();
                    }
                }
            }

            for(auto &SceneObject : SceneObjects) {
                if(Mario->Collision(SceneObject)) {
                    glm::vec2 SceneObject_right_up = {SceneObject->GetPosition().x + SceneObject->GetScaledSize().x / 2,SceneObject->GetPosition().y + SceneObject->GetScaledSize().y / 2};
                    glm::vec2 SceneObject_right_down = {SceneObject->GetPosition().x + SceneObject->GetScaledSize().x / 2,SceneObject->GetPosition().y - SceneObject->GetScaledSize().y / 2};
                    glm::vec2 SceneObject_left_up = {SceneObject->GetPosition().x - SceneObject->GetScaledSize().x / 2,SceneObject->GetPosition().y + SceneObject->GetScaledSize().y / 2};
                    glm::vec2 SceneObject_left_down = {SceneObject->GetPosition().x - SceneObject->GetScaledSize().x / 2,SceneObject->GetPosition().y - SceneObject->GetScaledSize().y / 2};

                    glm::vec2 Mario_right_up = {Mario->GetPosition().x + abs(Mario->GetScaledSize().x / 2),Mario->GetPosition().y + abs(Mario->GetScaledSize().y / 2)};
                    glm::vec2 Mario_right_down = {Mario->GetPosition().x + abs(Mario->GetScaledSize().x / 2),Mario->GetPosition().y - Mario->GetScaledSize().y / 2};
                    glm::vec2 Mario_left_up = {Mario->GetPosition().x - abs(Mario->GetScaledSize().x / 2),Mario->GetPosition().y + Mario->GetScaledSize().y / 2};
                    glm::vec2 Mario_left_down = {Mario->GetPosition().x - abs(Mario->GetScaledSize().x / 2),Mario->GetPosition().y - Mario->GetScaledSize().y / 2};
                }
            }
        }
    private:
        glm::vec2 MapPosition;
        glm::vec2 MapSize;
};
#endif //MAPMANERGER_HPP
