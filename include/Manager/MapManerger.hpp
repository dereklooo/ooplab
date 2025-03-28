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

#include "Monsters/Monster.hpp"
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
        MapManager(glm::vec2 MapPosition) {
            this->MapPosition = MapPosition;
        }
        void SetFloor(std::vector<glm::vec2> &Position,size_t Floor_y) {

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
        void MonsterCollision(std::vector<std::shared_ptr<Monster>>) {

        }
        void SceneObjectCollision(std::vector<std::shared_ptr<SceneObject>>) {

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
                    if(Mario->GetPosition().y > SceneObject->GetPosition().y) {
                        Mario->SetPosition({Mario->GetPosition().x,SceneObject->GetPosition().y + SceneObject->GetScaledSize().y / 2 + Mario->GetScaledSize().y / 2});
                    }
                    else if(Mario->GetPosition().y < SceneObject->GetPosition().y) {
                        Mario->SetPosition({Mario->GetPosition().x,SceneObject->GetPosition().y - SceneObject->GetScaledSize().y / 2 - Mario->GetScaledSize().y / 2});
                    }
                }
            }
        }
    private:
        glm::vec2 MapPosition;
};
#endif //MAPMANERGER_HPP
