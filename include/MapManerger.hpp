//
// Created by Benson on 2025/3/24.
//

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP
#include "SceneObject.hpp"

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
    private:
        glm::vec2 MapPosition;
};
#endif //MAPMANERGER_HPP
