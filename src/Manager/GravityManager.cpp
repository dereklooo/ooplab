//
// Created by Benson on 2025/4/27.
//
#include "Manager/GravityManager.hpp"

#include "Block/Flag.hpp"
#include "spdlog/async_logger.h"

GravityManager::GravityManager(
    std::shared_ptr<Mario>& mario,
    std::vector<std::shared_ptr<FireBall> > &FireBalls,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>> &Blocks,
    std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>> &Monsters,
    std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>> &Items) :
    Blocks(Blocks),
    Monsters(Monsters),
    Items(Items),
    FireBalls(FireBalls),
    Mario_(mario){

}
void GravityManager::Update() {
        this->Combination();
        for(auto &object : GravityObject) {
            const float deltaTime = Util::Time::GetDeltaTimeMs() / 1000.0f;
            if(IsFalling(object)) {
                object->SetFalling(true);
                if(object->GetGravity() >= 35) {
                    object->SetGravity(35);
                }
                else {
                    object->SetGravity(object->GetGravity() + gravity * deltaTime * 2.5);
                }
            }
            else {
                if(object->GetWCollision() == true) {
                    object->SetGravity(0);
                    object->SetFalling(false);
                }
                else {
                    if(object->GetGravity() >= 35) {
                        object->SetGravity(35);
                    }
                    else {
                        object->SetGravity(object->GetGravity() + gravity * deltaTime * 2.5);
                    }
                }
            }
            object->SetFallingTime(Util::Time::GetElapsedTimeMs());
            if (Mario_->GetTouchFlagFlag()==false || Mario_->GetMarioGoDoorFlag()==true) {
                object->SetPosition({object->GetPosition().x,object->GetPosition().y - object->GetGravity()});
            }

        }
}
void GravityManager::Combination() {
    GravityObject.clear();
    GravityObject.push_back(Mario_);
    for(auto &[type,monsters] : (*Monsters)) {
        for(auto &monster : monsters) {
            GravityObject.push_back(monster);
        }
    }
    for(auto &[type,items] : (*Items)) {
        for(auto &item : items) {
            if(item->GetState() != ItemState::Hidden) {
                GravityObject.push_back(item);
            }
        }
    }
    for(const auto& FireBall : FireBalls) {
        GravityObject.push_back(FireBall);
    }
}
bool GravityManager::IsFalling(const std::shared_ptr<Object> &object) const {
    if (object->GetWCollision() == false) return false;
    float gravity = object->GetGravity();
    if (gravity < 0.0f) return true;

    float curY = object->GetPosition().y;
    float nextY = curY - gravity;
    float curX = object->GetPosition().x;

    float objHalfW = std::abs(object->GetScaledSize().x / 2.0f);
    float objHalfH = std::abs(object->GetScaledSize().y / 2.0f);

    float bottomY = curY - objHalfH;
    float nextBottomY = nextY - objHalfH;

    for (const auto& [type, blocks] : *Blocks) {
        for (const auto& block : blocks) {
            if (block->GetType() == BlockType::flag || block->GetType() == BlockType::flagpole)
                continue;
            if (!block->GetVisible() || block->GetScaledSize().x < 0.1f || block->GetScaledSize().y < 0.1f)
                continue;

            float blockTop = block->GetPosition().y + std::abs(block->GetScaledSize().y / 2.0f);
            float blockX = block->GetPosition().x;
            float blockHalfW = std::abs(block->GetScaledSize().x / 2.0f);

            // 角色腳底預測會"穿過"方塊頂部 & X軸「重疊區」才會落地，不會因為側邊碰撞誤判
            float objLeft  = curX - objHalfW + 0.5f;
            float objRight = curX + objHalfW - 0.5f;
            float blockLeft  = blockX - blockHalfW;
            float blockRight = blockX + blockHalfW;

            if (
                bottomY > blockTop &&
                nextBottomY <= blockTop &&
                objRight > blockLeft &&
                objLeft < blockRight
            ) {
                // 落地矯正
                object->SetPosition({
                    object->GetPosition().x,
                    blockTop + objHalfH + 0.5f
                });
                object->SetFalling(false);
                return false;
            }

            // DownCollision 只會發生在腳底（你的 MarioManager 裡 DownCollision 實作已經是正確底邊判斷）
            if (
                (object->DownCollision(block) ||
                 (Mario_->GetTouchFlagFlag() && !Mario_->GetMarioGoDoorFlag())) &&
                block->GetType() != BlockType::flag && block->GetType() != BlockType::flagpole
            ) {
                object->SetFalling(false);
                return false;
            }
        }
    }
    object->SetFalling(true);
    return true;
}
