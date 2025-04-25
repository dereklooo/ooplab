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

class MonsterManager {
public:
    explicit MonsterManager(std::vector<std::shared_ptr<SceneObject>> &sceneObjects,std::vector<std::shared_ptr<Monster>> &Monsters);

    void AddMonster(const std::vector<std::shared_ptr<Monster>>& monsters, const std::shared_ptr<Util::Renderer> &renderer);
    void MonsterCollision() const;
    std::vector<std::shared_ptr<Monster>> GetByType(MonsterType type);

private:
    std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>> MonsterMap;
    std::vector<std::shared_ptr<Monster>> &AllMonsters;

    std::vector<std::shared_ptr<SceneObject>> &SceneObjects;
};
