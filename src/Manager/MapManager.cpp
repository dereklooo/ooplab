//
// Created by Benson on 2025/4/25.
//
#include "Manager/MapManager.hpp"
MapManager::MapManager(
    std::shared_ptr<Mario> &Mario,
    std::shared_ptr<Map> &Background,
    std::vector<std::shared_ptr<FireBall>> &FireBalls,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
    std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
    std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items) :
    Mario_(Mario),
    FireBalls(FireBalls),
    Blocks(Blocks),
    Monsters(Monsters),
    Items(Items),
    Background(Background) {}
void MapManager::GameObject_Move() const {
    if(Mario_->GetPosition().x - 1 <= -620) {
        Mario_->SetPosition({-620,Mario_->GetPosition().y});
    }
    if (Mario_->GetPosition().x >= 0) {
        Background->SetPosition({Background->GetPosition().x - 4,Background->GetPosition().y});
        Mario_->SetPosition({Mario_->GetPosition().x - 4,Mario_->GetPosition().y});
        for(const auto& [type,monsters] : (*Monsters)) {
            for(const auto &monster : monsters) {
                monster->SetPosition({monster->GetPosition().x - 4,monster->GetPosition().y});
            }
        }
        for (const auto& [type,blocks] : (*Blocks)) {
            for(const auto &block : blocks) {
                block->SetPosition({block->GetPosition().x - 4 , block->GetPosition().y});
            }
        }
        for(auto &[type,items] : (*Items)) {
            for(const auto &item : items) {
                item->SetPosition({item->GetPosition().x - 4 , item->GetPosition().y});
            }
        }
        for(const auto &fireball : FireBalls) {
            fireball->SetPosition({fireball->GetPosition().x - 4 , fireball->GetPosition().y});
        }
    }

    if(Mario_->GetPosition().y <= -250 && Mario_->GetAnimating() == true) {
        if(Mario_->GetNextPosition() == glm::vec2(0,0)) {
            Background->SetPosition({Background->GetPosition().x - Mario_->GetPosition().x,Background->GetPosition().y + 816});
        }
        else{
            Background->SetPosition({Background->GetPosition().x - Mario_->GetPosition().x,Background->GetPosition().y - 816});
        }


        for(auto &[Type,monsters] : *Monsters) {
            for(const auto& monster : monsters) {
                monster->SetVisible(false);
            }
        }
        Monsters->clear();
        for(auto &[Type,items] : *Items) {
            for(const auto &item : items) {
                if(Mario_->GetNextPosition() == glm::vec2(0,0)){
                    item->SetPosition({item->GetPosition().x - Mario_->GetPosition().x, item->GetPosition().y + 816});
                }
                else {
                    item->SetPosition({item->GetPosition().x - Mario_->GetPosition().x, item->GetPosition().y - 816});
                }
            }
        }
        for(auto &[Type,blocks] : *Blocks) {
            for(const auto& block : blocks) {
                if(Mario_->GetNextPosition() == glm::vec2(0,0)){
                    block->SetPosition({block->GetPosition().x - Mario_->GetPosition().x, block->GetPosition().y + 816});
                }
                else {
                    block->SetPosition({block->GetPosition().x - Mario_->GetPosition().x, block->GetPosition().y - 816});
                }
            }
        }
        if(Mario_->GetNextPosition() == glm::vec2(0,0)) {
            Mario_->SetAcceleration(0.0f);
            Mario_->SetPosition({-75,400});
            Mario_->SetGravity(0);
            Mario_->SetWCollision(true);
            Mario_->SetFallingTime(Util::Time::GetElapsedTimeMs());
            Mario_->SetCanMove(true);
            Mario_->UpDateCurrentState(Stand);
            Mario_->SetAnimation(false);
            Background->SetFloor(Background->GetFloor() - 1);
        }
        else {
            Mario_->SetAcceleration(0.0f);
            for(auto& [Type,items] : *Items) {
                for(const auto &item : items) {
                    item->SetPosition({item->GetPosition().x - Mario_->GetNextPosition().x,item->GetPosition().y});
                }
            }
            for(auto & [Type,blocks] : *Blocks) {
                for(const auto &block : blocks) {
                    block->SetPosition({block->GetPosition().x - Mario_->GetNextPosition().x,block->GetPosition().y});
                }
            }
            Background->SetPosition({Background->GetPosition().x - Mario_->GetNextPosition().x,Background->GetPosition().y});
            Mario_->SetPosition({-120,-120});
            Mario_->SetWCollision(true);
            Mario_->SetCanMove(true);
            Mario_->UpDateCurrentState(Stand);
            Mario_->SetAnimation(false);
            Background->SetFloor(Background->GetFloor() + 1);
        }
    }
}
