#include "Manager/MonsterManager.hpp"

MonsterManager::MonsterManager(std::vector<std::shared_ptr<SceneObject>> &sceneObjects,std::vector<std::shared_ptr<Monster>> &Monsters)
    : AllMonsters(Monsters),
    SceneObjects(sceneObjects) {}

void MonsterManager::AddMonster(const std::vector<std::shared_ptr<Monster>>& monsters, const std::shared_ptr<Util::Renderer> &renderer) {
    for(auto &monster : monsters) {
        MonsterMap[monster->GetType()].push_back(monster);
        AllMonsters.push_back(monster);
        renderer->AddChild(monster);
    }
}

std::vector<std::shared_ptr<Monster>> MonsterManager::GetByType(const MonsterType type) {
    return MonsterMap[type];
}

void MonsterManager::MonsterCollision() const {
    for (const auto &monster : AllMonsters) {
        for (const auto &scene : SceneObjects) {
            if (monster->LeftCollision(scene)) {
                monster->SetWay(Way::Right);
            } else if (monster->RightCollision(scene)) {
                monster->SetWay(Way::Left);
            }
            if (monster->DownCollision(scene)) {
                monster->SetPosition({
                    monster->GetPosition().x,
                    scene->GetPosition().y
                    + abs(scene->GetScaledSize().y / 2)
                    + abs(monster->GetScaledSize().y / 2) + 1
                });
            }
        }

        for (const auto &_monster : AllMonsters) {
            if (_monster != monster && !monster->GetDie() && !_monster->GetDie()) {
                if (_monster->LeftCollision(monster)) {
                    _monster->SetWay(Way::Right);
                    monster->SetWay(Way::Left);
                } else if (_monster->RightCollision(monster)) {
                    _monster->SetWay(Way::Left);
                    monster->SetWay(Way::Right);
                }
            }
        }
    }
}
