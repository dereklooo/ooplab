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
            case MonsterType::Red_turtle:
                if (monster->LeftCollision(block)) {
                    monster->SetWay(Way::Right);
                }
                else if (monster->RightCollision(block)) {
                    monster->SetWay(Way::Left);
                }
            break;
            case MonsterType::Fly_turtle:
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
                //std::cout<<monster->GetWay()<< std::endl;

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
                if(_monster->GetType() == Turtle_Type) {
                    if(std::dynamic_pointer_cast<Turtle>(_monster)->GetTurtleTye() == Rolling) {
                        break;
                    }
                }
                if ((temp->GetTurtleTye() == Inside || temp->GetTurtleTye() == OutSide)) {
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
                        _monster->SetDie(true);
                        _monster->SetKnockAway(true);
                        _monster->SetWCollision(false);
                        _monster->SetSize({_monster->GetSize().x, _monster->GetSize().y * -1});
                        _monster->SetGravity(-2.0f);
                    }
                }
                break;
            }
            case MonsterType::Red_turtle:{
                const auto temp = std::dynamic_pointer_cast<RedTurtle>(monster);
                if(_monster->GetType() == Red_turtle) {
                    if(std::dynamic_pointer_cast<RedTurtle>(_monster)->GetTurtleTye() == Rolling) {
                        break;
                    }
                }
                if ((temp->GetTurtleTye() == Inside || temp->GetTurtleTye() == OutSide)) {
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
                        _monster->SetDie(true);
                        _monster->SetKnockAway(true);
                        _monster->SetWCollision(false);
                        _monster->SetSize({_monster->GetSize().x, _monster->GetSize().y * -1});
                        _monster->SetGravity(-2.0f);
                    }
                }
                break;
            }
            case MonsterType::Fly_turtle:{
                const auto temp = std::dynamic_pointer_cast<FlyTurtle>(monster);
                if(_monster->GetType() == Fly_turtle) {
                    if(std::dynamic_pointer_cast<FlyTurtle>(_monster)->GetTurtleTye() == Rolling) {
                        break;
                    }
                }
                if ((temp->GetTurtleTye() == Inside || temp->GetTurtleTye() == OutSide)) {
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
                        _monster->SetDie(true);
                        _monster->SetKnockAway(true);
                        _monster->SetWCollision(false);
                        _monster->SetSize({_monster->GetSize().x, _monster->GetSize().y * -1});
                        _monster->SetGravity(-2.0f);
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