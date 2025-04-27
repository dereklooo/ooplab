#include "Manager/MonsterManager.hpp"

MonsterManager::MonsterManager(
    std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>>& Monsters,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks) :
    Monsters(Monsters),
    Blocks(Blocks){

}


void MonsterManager::AddMonster(const std::vector<std::shared_ptr<Monster>>& monsters, const std::shared_ptr<Util::Renderer> &renderer) const {
    for(auto &monster : monsters) {
        (*Monsters)[monster->GetType()].push_back(monster);
        renderer->AddChild(monster);
    }
}

void MonsterManager::MonsterCollision() const {
    for (const auto &[type_M,monster] : Monsters) {
        for (const auto &[type_B,block] : Blocks) {
            HandleBlockCollision(type_M,monster,block);
        }
        for (const auto &[type_M,_monster] : Monsters) {
            HandleMonsterCollision(_monster,monster);
        }
    }
}
void MonsterManager::HandleBlockCollision(const MonsterType type,const std::shared_ptr<Monster>& monster, const std::shared_ptr<SceneObject>& block) {
    if(monster->GetWCollision()) {
        switch (type) {
            case Mushroom_Type:
                if (monster->LeftCollision(block)) {
                    monster->SetWay(Way::Right);
                } else if (monster->RightCollision(block)) {
                    monster->SetWay(Way::Left);
                }
            break;
            case Turtle_Type:
                if (monster->LeftCollision(block)) {
                    monster->SetWay(Way::Right);
                } else if (monster->RightCollision(block)) {
                    monster->SetWay(Way::Left);
                }
            break;
            default: ;
        }
        if (monster->DownCollision(block)) {
            monster->SetPosition({
                monster->GetPosition().x,
                block->GetPosition().y
                + abs(block->GetScaledSize().y / 2)
                + abs(monster->GetScaledSize().y / 2) + 1
            });
        }
    }
}
void HandleMonsterCollision(const std::shared_ptr<Monster>& monster, const std::shared_ptr<Monster>& _monster) {
    if (_monster != monster && !monster->GetDie() && !_monster->GetDie()) {
        if (_monster->LeftCollision(monster)) {
            _monster->SetWay(Way::Right);
            monster->SetWay(Way::Left);
        } else if (_monster->RightCollision(monster)) {
            _monster->SetWay(Way::Left);
            monster->SetWay(Way::Right);
        } //之後加入烏龜的龜殼
    }
}