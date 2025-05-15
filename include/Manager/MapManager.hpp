//
// Created by Benson on 2025/3/29.
//

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP
#include "Mario/FireBall.hpp"
#include "Monsters/Monster.hpp"
#include "Mario/Mario.hpp"
#include "Object/ItemObject.hpp"
#include "Object/SceneObject.hpp"
#include "Map/Map.hpp"
#include "Util/Input.hpp"

class MapManager {
    public:
    MapManager(std::shared_ptr<Mario>& Mario,
        std::shared_ptr<Map>& Background,
        std::vector<std::shared_ptr<FireBall>>& FireBalls,
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
        std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items);

        void GameObject_Move() const;
        void CtlMarioPipeMove() const;
        void Update() const {
            GameObject_Move();
            CtlMarioPipeMove();


        }
    private:
        std::shared_ptr<Mario>& Mario_;
        std::vector<std::shared_ptr<FireBall>> &FireBalls;
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters;
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items;
        std::shared_ptr<Map>& Background;
};
#endif //MAPMANAGER_HPP