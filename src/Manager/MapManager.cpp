//
// Created by Benson on 2025/4/25.
//
#include "Manager/MapManager.hpp"
MapManager::MapManager(
    std::shared_ptr<Mario> &Mario,
    std::shared_ptr<SceneObject> &Background,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>> &Blocks,
    std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>> &Monsters,
    std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>> &Items) :
    Mario_(Mario),
    Blocks(Blocks),
    Monsters(Monsters),
    Items(Items),
    Background(Background) {}
void GameObject_Move() {
    if (Mario_->GetPosition().x >= 0) {
        Background->SetPosition({m_Background->GetPosition().x - 4,m_Background->GetPosition().y});
        Mario->SetPosition({m_MariO->GetPosition().x - 4,m_MariO->GetPosition().y});
        for(const auto& monster : Monsters) {
            monster->SetPosition({monster->GetPosition().x - 4,monster->GetPosition().y});
        }
        for (const auto& [type,Object] : Blocks) {
            Object->SetPosition({Object->GetPosition().x - 4 , Object->GetPosition().y});
        }
        for (const auto& Object : Blocks) {
            Object->SetPosition({Object->GetPosition().x - 4 , Object->GetPosition().y});
        }
    }
    if(m_Background->GetPosition().x <= 500 && m_MariO->GetPosition().y <= -350) {
        m_MariO->SetPosition({m_MariO->GetPosition().x,0});
    }
}