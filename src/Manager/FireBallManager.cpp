//
// Created by benson on 2025/5/2.
//
#include "Manager/FireBallManager.hpp"

#include <iostream>
#include <ostream>

FireBallManager::FireBallManager(
    std::shared_ptr<Mario>& Mario,
    std::shared_ptr<Util::Renderer>& renderer,
    std::vector<std::shared_ptr<FireBall>>& Fireballs,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>> &Blocks,
    std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>> &Monsters) :
    Blocks(Blocks),
    FireBalls(Fireballs),
    Monsters(Monsters),
    renderer(renderer),
    Mario_(Mario){

}
void FireBallManager::HandleBlocksCollision(const std::shared_ptr<FireBall> &FireBall) const {
    for(const auto &[BlockType,blocks] : *Blocks) {
        for(const auto &block : blocks) {
            if(FireBall->LeftCollision(block) || FireBall->RightCollision(block) || FireBall->UpCollision(block)) {
                FireBall->SetState(Explode);
            }
        }
    }
}

void FireBallManager::HandleMonsterCollision(const std::shared_ptr<FireBall> &FireBall)  const{
    for(const auto &[MonsterType,monsters] : *Monsters) {
        for(const auto &monster : monsters) {
            if((FireBall->LeftCollision(monster) || FireBall->RightCollision(monster) || FireBall->UpCollision(monster) || FireBall->DownCollision(monster)) && monster->GetDie() == false) {
                FireBall->SetState(Explode);
                monster->SetDie(true);
                monster->SetKnockAway(true);
                monster->SetWCollision(false);
                monster->SetSize({monster->GetSize().x, monster->GetSize().y * -1});
                monster->SetGravity(-2.0f);
            }
        }
    }
}

void FireBallManager::Update() {
    if(Mario_->GetShooting()) {
        const auto temp = std::make_shared<FireBall>(Mario_->GetPosition());
        if(Mario_->GetSize().x < 0) {
            temp->SetWay(Left);
        }
        else {
            temp->SetWay(Right);
        }
        temp->SetSize({1.5,1.5});
        temp->SetVisible(true);
        FireBalls.push_back(temp);
        renderer->AddChild(temp);
    }
    Mario_->SetShooting(false);
    for (size_t i = 0; i < FireBalls.size(); ) {
        auto& fireball = FireBalls[i];

        HandleBlocksCollision(fireball);
        HandleMonsterCollision(fireball);

        if (fireball->GetState() == Roll) {
            fireball->Rolling();
            ++i;
        }
        else if (fireball->GetState() == Explode) {
            fireball->Explode();
            ++i;
        }
        else if (fireball->GetState() == End) {
            return; //從這邊改
        }
    }
}
