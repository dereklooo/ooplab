//
// Created by Benson on 2025/3/29.
//

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP
#include "Block/OriginalBlock.hpp"
#include "Block/LuckyBlock.hpp"
#include "Block/FootBlock.hpp"
#include "Block/Pipe_64_128.hpp"
#include "Block/Pipe_64_96.hpp"
#include "Block/Pipe_64_64.hpp"
#include "Block/AirBlock.hpp"
#include "Monsters/Mushroom.hpp"
#include "Monsters/Turtle.hpp"
#include "Mario/Mario.hpp"

#include "GravityManager.hpp"
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
        void SetFloor(std::vector<std::shared_ptr<SceneObject>>& SceneManager,std::vector<float> &Position, const float Floor_y) const {
            for(float i = 0.5f ; i <= MapSize.x / 32 ; i++) {
                bool Build = true;
                for(const float position : Position) {
                    if(position == i) {
                        Build = false;
                    }
                }
                if(Build) {
                    auto temp = std::make_shared<AirBlock>(glm::vec2(MapPosition.x + i * 48 , MapPosition.y + Floor_y * 48));
                    temp->SetSize({1.5,1.5});
                    temp->SetZIndex(100);
                    SceneManager.push_back(temp);
                    temp = std::make_shared<AirBlock>(glm::vec2(MapPosition.x + i * 48 , MapPosition.y + (Floor_y - 1) * 48));
                    temp->SetSize({1.5,1.5});
                    temp->SetZIndex(100);
                    SceneManager.push_back(temp);
                }
            }
        }
        void SetBlock(std::vector<std::shared_ptr<SceneObject>>& SceneManager,std::vector<glm::vec2> &Position, const BlockType type) const {
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
                temp->SetZIndex(100);
                temp->SetSize({1.5,1.5});
                SceneManager.push_back(temp);
            }
        }
        static void AddMonster(const std::vector<std::shared_ptr<Monster>> &monsters,const std::shared_ptr<Util::Renderer> &renderer,std::vector<std::shared_ptr<Monster>> &Monsters) {
            for (auto &monster : monsters) {
                renderer->AddChild(monster);
                Monsters.push_back(monster);
            }
        }
        static void MonsterCollision(const std::vector<std::shared_ptr<Monster>> &Monsters,const std::vector<std::shared_ptr<SceneObject>> &SceneObjects) {
            for(const auto &Monster : Monsters) {
                for(const auto& SceneObject : SceneObjects) {
                    if(Monster->LeftCollision(SceneObject)) {
                        Monster->SetWay(Way::Right);
                    }
                    else if(Monster->RightCollision(SceneObject)) {
                        Monster->SetWay(Way::Left);
                    }
                    if(Monster->DownCollision(SceneObject)) {
                        Monster->SetPosition({Monster->GetPosition().x,SceneObject->GetPosition().y + abs(SceneObject->GetScaledSize().y / 2) + abs(Monster->GetScaledSize().y / 2) + 1});
                    }
                }
                for(const auto &_Monster : Monsters) {
                    if (_Monster != Monster) {
                        if(_Monster->LeftCollision(Monster) && !Monster->GetDie() && !_Monster->GetDie()) {
                            _Monster->SetWay(Way::Right);
                            Monster->SetWay(Way::Left);
                        }
                        else if(_Monster->RightCollision(Monster) && !Monster->GetDie() && !_Monster->GetDie()) {
                            _Monster->SetWay(Way::Left);
                            Monster->SetWay(Way::Right);
                        }
                    }
                }
            }
        }
        static void MarioCollision(const std::shared_ptr<Mario>& Mario,const std::vector<std::shared_ptr<Monster>>& Monsters,const std::vector<std::shared_ptr<SceneObject>>& SceneObjects) {
            for(auto &monster : Monsters) {
                if((Mario->RightCollision(monster) || Mario->LeftCollision(monster)) && !monster->GetDie()) {
                    Mario->Hurt();
                }
                else if(Mario->DownCollision(monster) && !monster->GetDie()) {
                        monster->Hurt();
                        Mario->SetGravity(-2.0f);
                }
            }
            for(auto &SceneObject : SceneObjects) {
                if(Mario->LeftCollision(SceneObject)) {
                    Mario->SetPosition({SceneObject->GetPosition().x + abs(SceneObject->GetScaledSize().x / 2) + abs(Mario->GetScaledSize().x / 2) + 5,Mario->GetPosition().y});
                }
                else if(Mario->RightCollision(SceneObject)) {
                    Mario->SetPosition({SceneObject->GetPosition().x - abs(SceneObject->GetScaledSize().x / 2) - abs(Mario->GetScaledSize().x / 2) - 5,Mario->GetPosition().y});
                }
                if(Mario->UpCollision(SceneObject)) {
                    Mario->SetPosition({Mario->GetPosition().x,SceneObject->GetPosition().y - abs(SceneObject->GetScaledSize().y / 2) - abs(Mario->GetScaledSize().y / 2) - 5});
                    Mario->SetGravity(2);
                    SceneObject->hit(Mario);
                }
                else if(Mario->DownCollision(SceneObject)) {
                    Mario->SetPosition({Mario->GetPosition().x,SceneObject->GetPosition().y + abs(SceneObject->GetScaledSize().y / 2) + abs(Mario->GetScaledSize().y / 2) + 1});
                }
            }
        }
        static void Update(const std::shared_ptr<Mario>& Mario,
            const std::vector<std::shared_ptr<Monster>>& Monsters,
            const std::vector<std::shared_ptr<SceneObject>>& SceneObjects) {

            for (const auto& monster : Monsters) {
                monster->Action();
            }
            MonsterCollision(Monsters,SceneObjects);
            MarioCollision(Mario,Monsters,SceneObjects);
        }
    private:
        glm::vec2 MapPosition;
        glm::vec2 MapSize;
};
#endif //MAPMANAGER_HPP
