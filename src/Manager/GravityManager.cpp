//
// Created by Benson on 2025/4/27.
//
#include "Manager/GravityManager.hpp"

#include "Block/Flag.hpp"

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
    if(object->GetWCollision() == false) return false;
    float gravity = object->GetGravity();
    if (gravity <= 0.0f) return true;

    float curY = object->GetPosition().y;
    float nextY = curY - gravity;

    float bottomY = curY - std::abs(object->GetScaledSize().y / 2.0f);
    float nextBottomY = nextY - std::abs(object->GetScaledSize().y / 2.0f);

    for (const auto& [type, blocks] : *Blocks) {
        for (const auto& block : blocks) {
            if (block->GetType() == BlockType::flag || block->GetType() == BlockType::flagpole)
                continue;

            float blockTop = block->GetPosition().y + std::abs(block->GetScaledSize().y / 2.0f);

            for (const auto& [type, blocks] : *Blocks) {
                for (const auto& block : blocks) {
                    if (block->GetType() == BlockType::flag || block->GetType() == BlockType::flagpole)
                        continue;
                    if (!block->GetVisible() || block->GetScaledSize().x < 0.1f || block->GetScaledSize().y < 0.1f)
                        continue;

                    float blockTop = block->GetPosition().y + std::abs(block->GetScaledSize().y / 2.0f);

                    // ✅ 預測落地：重力導致位置變化是否會「穿越方塊上邊界」
                    if (bottomY > blockTop && nextBottomY <= blockTop) {
                        float dx = std::abs(object->GetPosition().x - block->GetPosition().x);
                        float maxDx = std::abs(object->GetScaledSize().x / 2.0f) + std::abs(block->GetScaledSize().x / 2.0f);

                        if (dx <= maxDx) {
                            // ✅ 修正落地位置，避免穿透
                            object->SetPosition({
                                object->GetPosition().x,
                                block->GetPosition().y + std::abs(block->GetScaledSize().y / 2.0f) + std::abs(object->GetScaledSize().y / 2.0f) + 0.5f
                            });

                            object->SetGravity(0.0f);
                            object->SetFalling(false);
                            return false;
                        }
                    }


                    // 原本的簡單 DownCollision 邏輯保留，避免極小 gravity 跳過機制時沒偵測到
                    if ((object->DownCollision(block) || (Mario_->GetTouchFlagFlag() && !Mario_->GetMarioGoDoorFlag())) &&
                        block->GetType() != BlockType::flag && block->GetType() != BlockType::flagpole) {
                        object->SetFalling(false);
                        return false;
                        }
                }
            }

            object->SetFalling(true);
            return true;
        }
    }
}