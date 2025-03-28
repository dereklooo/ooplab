//
// Created by Benson on 2025/3/24.
//

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP
#include "Object/SceneObject.hpp"
#include "Monsters/Monster.hpp"
#include "Mario/Mario.hpp"
#include <iostream>
class MapManager {
    public:
        MapManager(glm::vec2 MapPosition) {
            this->MapPosition = MapPosition;
        };
        std::vector<std::shared_ptr<SceneObject>> SetBlock(std::vector<glm::vec2> Position,std::string Path) {
            std::vector<std::shared_ptr<SceneObject>> ScenceManager;
            for (auto position : Position) {
                auto temp = std::make_shared<SceneObject>(Path,glm::vec2(MapPosition.x + position.x * 48 , MapPosition.y + position.y * 48));
                temp->SetZIndex(50);
                temp->SetSize({1.5,1.5});
                ScenceManager.push_back(temp);
            }
            return ScenceManager;
        }
        void MonsterCollision(std::vector<std::shared_ptr<Monster>>) {

        }
        void SceneObjectCollision(std::vector<std::shared_ptr<SceneObject>>) {

        }
        static void Update(const std::shared_ptr<m_mariO>& Mario,
            const std::vector<std::shared_ptr<Monster>>& Monsters,
            const std::vector<std::shared_ptr<SceneObject>>& SceneObjects) {

            for(auto &monster : Monsters) {
                if(Mario->Collision(monster)) {
                    if(Mario->GetPosition().y - Mario->GetScaledSize().y / 2 >= monster->GetPosition().y) {
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
