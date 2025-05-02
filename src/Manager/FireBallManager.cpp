//
// Created by benson on 2025/5/2.
//
#include "Manager/FireBallManager.hpp"
FireBallManager::FireBallManager(
    std::shared_ptr<Mario>& Mario,
    std::vector<std::shared_ptr<FireBall>>& FireBalls,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>> &Blocks,
    std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>> &Monsters) :
    Blocks(Blocks),
    Monsters(Monsters),
    FireBalls(FireBalls),
    Mario_(Mario){

}
void FireBallManager::HandleBlocksCollision(const std::shared_ptr<FireBall> &FireBall) const {
    for(const auto &[BlockType,blocks] : *Blocks) {
        for(const auto &block : blocks) {
            if(FireBall->LeftCollision(block) || FireBall->RightCollision(block) || FireBall->UpCollision(block) || FireBall->DownCollision(block)) {
                FireBall->SetState(Exploding);
            }
            else {
                FireBall->SetState(Rolling);
            }
        }
    }
}

void FireBallManager::HandleMonsterCollision(const std::shared_ptr<FireBall> &FireBall)  const{
    for(const auto &[MonsterType,monsters] : *Monsters) {
        for(const auto &monster : monsters) {
            if((FireBall->LeftCollision(monster) || FireBall->RightCollision(monster) || FireBall->UpCollision(monster) || FireBall->DownCollision(monster)) && monster->GetDie() == false) {
                FireBall->SetState(Exploding);
                monster->SetDie(true);
                monster->SetKnockAway(true);
                monster->SetWCollision(false);
                monster->SetSize({monster->GetSize().x, monster->GetSize().y * -1});
                monster->SetGravity(-2.0f);
            }
            else {
                FireBall->SetState(Rolling);
            }
        }
    }
}

void FireBallManager::update() const {
    if(Mario_->GetShooting()) {
        
    }
    else {

    }
    for(auto& FireBall : FireBalls) {
        HandleBlocksCollision(FireBall);
        HandleMonsterCollision(FireBall);
        if(FireBall->GetState() ==  Exploding) {
            FireBall->Explode();
        }
        else if(FireBall->GetState() == Rolling) {
            FireBall->Rolling();
        }
    }
}
