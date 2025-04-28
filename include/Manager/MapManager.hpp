//
// Created by Benson on 2025/3/29.
//

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP
#include "Monsters/Monster.hpp"
#include "Mario/Mario.hpp"
#include "Object/ItemObject.hpp"
#include "Object/SceneObject.hpp"

class MapManager {
    public:
    MapManager(std::shared_ptr<Mario>& Mario,
        std::shared_ptr<StillObject>& Background,
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
        std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items);

        void GameObject_Move() const;
        void Update() const {
            GameObject_Move();
        }
    private:
        std::shared_ptr<Mario>& Mario_;
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters;
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items;
        std::shared_ptr<StillObject>& Background;
};
#endif //MAPMANAGER_HPP
