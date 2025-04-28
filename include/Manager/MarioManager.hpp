//
// Created by Benson on 2025/4/25.
//

#ifndef MARIOMANAGER_HPP
#define MARIOMANAGER_HPP
#include "Util/Input.hpp"
#include "Mario/Mario.hpp"
#include "Monsters/Monster.hpp"
#include "Block/Pipe_64_64.hpp"
#include "Block/Pipe_64_96.hpp"
#include "Block/Pipe_64_128.hpp"

class MarioManager {
    public:
        MarioManager(
            std::shared_ptr<Mario>& Mario,
            std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
            std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
            std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items);
        void MarioInitialize() const;
        void MarioCollision();
        void MarioInputCtl() const;
        void Update();
    private:
        void HandleMonster() const;
        void HandleBlock() const;
        std::shared_ptr<Mario>& Mario_;
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters;
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items;
};
#endif //MARIOMANAGER_HPP
