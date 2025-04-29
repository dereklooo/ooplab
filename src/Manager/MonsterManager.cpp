#include "Manager/MonsterManager.hpp"

#include <iostream>

MonsterManager::MonsterManager(
    std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>>& Monsters,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks) :
    Monsters(Monsters),
    Blocks(Blocks){

}


void MonsterManager::AddMonster(const std::vector<std::shared_ptr<Monster>>& monsters, const std::shared_ptr<Util::Renderer> &renderer) const {
    for(auto &monster : monsters) {
        monster->SetFallingTime(Util::Time::GetElapsedTimeMs());
        (*Monsters)[monster->GetType()].push_back(monster);
        renderer->AddChild(monster);
    }
}

void MonsterManager::MonsterCollision() const {
    for (const auto &[type_M,monsters] : (*Monsters)) {
        for(const auto &monster : monsters) {
            for (const auto &[type_B,blocks] : (*Blocks)) {
                for(const auto &block : blocks) {
                    HandleBlockCollision(type_M,monster,block);
                }
            }
            for (const auto &[type_M,_monsters] : (*Monsters)) {
                for(const auto &_monster : _monsters) {
                    HandleMonsterCollision(_monster,monster);
                }
            }
        }
    }
}
void MonsterManager::HandleBlockCollision(
    const MonsterType type,
    const std::shared_ptr<Monster>& monster,
    const std::shared_ptr<SceneObject>& block) {
    if(monster->GetWCollision()) {
        switch (type) {
            case MonsterType::Mushroom_Type:
                if (monster->LeftCollision(block)) {
                    monster->SetWay(Way::Right);
                }
                else if (monster->RightCollision(block)) {
                    monster->SetWay(Way::Left);
                }
                break;
            case MonsterType::Turtle_Type:
                if (monster->LeftCollision(block)) {
                    monster->SetWay(Way::Right);
                }
                else if (monster->RightCollision(block)) {
                    monster->SetWay(Way::Left);
                }
                break;
            default:
                break;
        }
        if (monster->DownCollision(block)) {
            monster->SetPosition({monster->GetPosition().x,block->GetPosition().y+ abs(block->GetScaledSize().y / 2)+ abs(monster->GetScaledSize().y / 2) + 1});
        }
    }
}
void MonsterManager::HandleMonsterCollision(const std::shared_ptr<Monster>& monster, const std::shared_ptr<Monster>& _monster) {
    if (_monster != monster && !monster->GetDie() && !_monster->GetDie()) {
        switch(monster->GetType()) {
            case MonsterType::Mushroom_Type: {
                if (monster->LeftCollision(_monster)) {
                    monster->SetWay(Way::Right);
                    if(_monster->GetType() != MonsterType::Turtle_Type) {
                        _monster->SetWay(Way::Left);
                    }
                }
                else if (monster->RightCollision(_monster)) {
                    monster->SetWay(Way::Left);
                    if(_monster->GetType() != MonsterType::Turtle_Type) {
                        _monster->SetWay(Way::Right);
                    }
                }
            }
            break;
            case MonsterType::Turtle_Type:{
                const auto temp = std::dynamic_pointer_cast<Turtle>(monster);
                if (temp->GetTurtleTye() == Inside || temp->GetTurtleTye() == OutSide) {
                    if (_monster->LeftCollision(monster)) {
                        _monster->SetWay(Way::Right);
                        monster->SetWay(Way::Left);
                    }
                    else if (_monster->RightCollision(monster)) {
                        _monster->SetWay(Way::Left);
                        monster->SetWay(Way::Right);
                    }
                }
                else if(temp->GetTurtleTye() == Rolling) {
                    if (_monster->LeftCollision(monster) || _monster->RightCollision(monster) || _monster->DownCollision(monster) || _monster->UpCollision(monster)) {
                        _monster->Hurt();
                    }
                }
                break;
            }
            default: {
                break;
            }
        }
         //之後加入烏龜的龜殼
    }
}