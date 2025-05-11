#pragma once
#include <unordered_map>
#include <vector>
#include <memory>

#include "Monsters/Monster.hpp"
#include "Monsters/Mushroom.hpp"
#include "Monsters/Turtle.hpp"
#include "Monsters/Black_turtle.hpp"
#include "Monsters/Eat_flower.hpp"
#include "Monsters/Fly_turtle.hpp"
#include "Monsters/Kooper.hpp"
#include "Monsters/Jump_turtle.hpp"

#include "Util/Renderer.hpp"
#include "Object/SceneObject.hpp"
#include <iostream>
class MonsterManager {
public:
    explicit MonsterManager(
        std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks);

    void AddMonster(const std::vector<std::shared_ptr<Monster>>& monsters, const std::shared_ptr<Util::Renderer> &renderer) const;
    void MonsterCollision() const;
    void Update() const{
        MonsterCollision();
        for(auto &[type,monsters] : *Monsters) {
            for(const auto &monster : monsters) {
                monster->Action();
            }
        }
    }
private:
    static void HandleMonsterCollision(const std::shared_ptr<Monster>& monster,const std::shared_ptr<Monster>& _monster);
    static void HandleBlockCollision(MonsterType type,const std::shared_ptr<Monster>& monster, const std::shared_ptr<SceneObject>& block);
    std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters;

    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
};
