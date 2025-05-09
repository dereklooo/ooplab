//
// Created by benson on 2025/4/3.
//

#ifndef GRAVITYMANAGER_HPP
#define GRAVITYMANAGER_HPP
#include <iostream>
#include <ostream>

#include "Util/Time.hpp"
#include "Mario/Mario.hpp"
#include "Mario/FireBall.hpp"
#include "Monsters/Monster.hpp"
#include "Object/ItemObject.hpp"
#include "Object/SceneObject.hpp"

class GravityManager {
    public:
            explicit GravityManager(
                std::shared_ptr<Mario>& mario,
                std::vector<std::shared_ptr<FireBall>>& FireBalls,
                std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
                std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>> &Monsters,
                std::shared_ptr<std::unordered_map<ItemType,std::vector<std::shared_ptr<ItemObject>>>> &Items);
            void Update();
            bool IsFalling(const std::shared_ptr<Object> &Object) const;
    private:
            void Combination();
            const float gravity = 18.0f;
            std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
            std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>>& Monsters;
            std::shared_ptr<std::unordered_map<ItemType,std::vector<std::shared_ptr<ItemObject>>>>& Items;
            std::vector<std::shared_ptr<FireBall>>& FireBalls;

            std::vector<std::shared_ptr<Object>> GravityObject;
            std::shared_ptr<Mario>& Mario_;
};
#endif
//GRAVITYMANAGER_HPP
