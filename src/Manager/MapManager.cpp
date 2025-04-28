//
// Created by Benson on 2025/4/25.
//
#include "Manager/MapManager.hpp"
MapManager::MapManager(
    std::shared_ptr<Mario> &Mario,
    std::shared_ptr<StillObject> &Background,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
    std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
    std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items) :
    Mario_(Mario),
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
    }

    if(Background->GetPosition().x <= 500 && Mario_->GetPosition().y <= -350) {
        Mario_->SetPosition({Mario_->GetPosition().x,0});
    }
}
