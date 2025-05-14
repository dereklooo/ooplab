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
            if(IsFalling(object)) {
                const float deltaTime = (Util::Time::GetElapsedTimeMs() - object->GetFallingTime()) / 1000.0f;
                const float gravityNow = object->GetGravity();
                const float gravityNext = gravityNow + gravity * deltaTime;
                object->SetGravity(gravityNext);
                object->SetFalling(true);
            }
            else {
                if(object->GetWCollision()) {
                    object->SetGravity(0.0f);
                    object->SetFalling(false);

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
bool GravityManager::IsFalling(const std::shared_ptr<Object> &Object) const{
        for(auto &[type,blocks] : (*Blocks)) {
            for(auto &block : blocks) {
                if(((Object->DownCollision(block) && Object->GetGravity() >= 0) || (Mario_->GetTouchFlagFlag()==true && Mario_->GetMarioGoDoorFlag()==false)) && (block->GetType()!=BlockType::flag && block->GetType()!=BlockType::flagpole)) {
                    Object->SetFalling(false);
                    return false;
                }
            }
        }
        Object->SetFalling(true);
        return true;
}