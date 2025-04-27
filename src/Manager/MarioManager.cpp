//
// Created by Benson on 2025/4/26.
//
#include "Manager/MarioManager.hpp"
MarioManager::MarioManager(
            std::shared_ptr<Mario> &Mario,
            std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
            std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
            std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items) :
            Mario_(Mario),
            Blocks(Blocks),
            Monsters(Monsters),
            Items(Items) {

            }
void MarioManager::HandleBlock() {
    for(const auto& [type,Block] : Blocks) {
        if(Mario_->LeftCollision(Block)) {
            Mario_->SetPosition({Block->GetPosition().x + abs(Block->GetScaledSize().x / 2) + abs(Mario_->GetScaledSize().x / 2) + 5,Mario_->GetPosition().y});
        }
        else if(Mario_->RightCollision(Block)) {
            Mario_->SetPosition({Block->GetPosition().x - abs(Block->GetScaledSize().x / 2) - abs(Mario_->GetScaledSize().x / 2) - 5,Mario_->GetPosition().y});
        }
        else if(Mario_->UpCollision(Block)) {
            Mario_->SetPosition({Mario_->GetPosition().x,Block->GetPosition().y - abs(Block->GetScaledSize().y / 2) - abs(Mario_->GetScaledSize().y / 2) - 5});
            Mario_->SetGravity(2);
            Block->hit(Mario_);
        }
        else if(Mario_->DownCollision(Block)) {
            Mario_->SetPosition({Mario_->GetPosition().x,Block->GetPosition().y + abs(Block->GetScaledSize().y / 2) + abs(Mario_->GetScaledSize().y / 2) + 1});
        }
    }
}
void MarioManager::HandleMonster() {
    for(auto &monster : Monsters) {
        if((Mario_->RightCollision(monster) || Mario_->LeftCollision(monster)) && !monster->GetDie()) {
            Mario_->Hurt();
        }
        else if(Mario_->DownCollision(monster) && !monster->GetDie()) {
            monster->Hurt();
            Mario_->SetGravity(-2.0f);
        }
    }
}

void MarioManager::MarioCollision() {
    HandleBlock();
    HandleMonster();
}