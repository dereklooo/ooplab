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
void MarioManager::HandleBlock() const {
    for (const auto& [type, blocks] : *Blocks) {   // 注意這裡，blocks 是 vector
        for (const auto& block : blocks) {          // 再一個 for loop
            if(Mario_->LeftCollision(block)) {
                Mario_->SetPosition({block->GetPosition().x + abs(block->GetScaledSize().x / 2) + abs(Mario_->GetScaledSize().x / 2) + 5, Mario_->GetPosition().y});
            }
            else if(Mario_->RightCollision(block)) {
                Mario_->SetPosition({block->GetPosition().x - abs(block->GetScaledSize().x / 2) - abs(Mario_->GetScaledSize().x / 2) - 5, Mario_->GetPosition().y});
            }
            else if(Mario_->UpCollision(block)) {
                Mario_->SetPosition({Mario_->GetPosition().x, block->GetPosition().y - abs(block->GetScaledSize().y / 2) - abs(Mario_->GetScaledSize().y / 2) - 5});
                Mario_->SetGravity(2);
                block->hit(Mario_);
            }
            else if(Mario_->DownCollision(block)) {
                Mario_->SetPosition({Mario_->GetPosition().x, block->GetPosition().y + abs(block->GetScaledSize().y / 2) + abs(Mario_->GetScaledSize().y / 2) + 1});
            }
        }
    }
}
void MarioManager::HandleItem() const {
    for (const auto& [type, items] : *Items) {
        for (const auto& item : items) {
            if(Mario_->LeftCollision(item)|| Mario_->RightCollision(item) || Mario_->DownCollision(item)) {
                item->SetVisible(false);
                item->SetWCollision(false);
                item->ChangeMarioState(Mario_);
            }
        }
    }
}
void MarioManager::HandleMonster() const {
    for(auto &[type,monsters] : *Monsters) {
        for(auto &monster : monsters) {
            if((Mario_->RightCollision(monster) || Mario_->LeftCollision(monster)) && !monster->GetDie()) {
                Mario_->Hurt();
            }
            else if(Mario_->DownCollision(monster) && !monster->GetDie()) {
                monster->Hurt();
                Mario_->SetGravity(-2.0f);
            }
        }
    }
}
void MarioManager::MarioInputCtl() const {
    if(Mario_->GetType() == Small) {
        if (Util::Input::IsKeyPressed(Util::Keycode::D)){
            Mario_->SetCurrentState(Run);
            Mario_->RightMove();
        }

        else if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
            Mario_->SetCurrentState(Run);
            Mario_->LeftMove();
        }

        if(Util::Input::IsKeyPressed(Util::Keycode::S)) {

        }
        if (Mario_->GetAcceleration()==0 && !Mario_->GetFalling()) {
            Mario_->SetCurrentState(Stand);
        }
        if(Util::Input::IsKeyPressed(Util::Keycode::W)) {
            Mario_->Jump();
            Mario_->SetCurrentState(Action::Jump);
        }
        Mario_->Brakes();
    }
    else if(Mario_->GetType() == Big) {
        if (Util::Input::IsKeyPressed(Util::Keycode::D)){
            Mario_->SetCurrentState(Run);
            Mario_->RightMove();
        }

        else if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
            Mario_->SetCurrentState(Run);
            Mario_->LeftMove();
        }

        if(Util::Input::IsKeyPressed(Util::Keycode::S)) {
            Mario_->SetCurrentState(Down);
        }
        if (Mario_->GetAcceleration()==0 && !Mario_->GetFalling()) {
            Mario_->SetCurrentState(Stand);
        }
        if(Util::Input::IsKeyPressed(Util::Keycode::W)) {
            Mario_->Jump();
            Mario_->SetCurrentState(Action::Jump);
        }
        Mario_->Brakes();
    }
    Mario_->UpDateCurrentState(Mario_->GetCurrentState());
}
void MarioManager::MarioInitialize() const {
    Mario_ = std::make_shared<Mario>();
    Mario_->SetGravity(-2.0f);
    Mario_->SetFallingTime(Util::Time::GetElapsedTimeMs());
    Mario_->SetPosition({-620,-150});
    Mario_->UpDateCurrentState(Stand);

    Mario_->SetZIndex(50);
    Mario_->SetSize({1.35,1.2});
}
void MarioManager::MarioCollision() const {
    HandleItem();
    HandleBlock();
    HandleMonster();
}
