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
            if(FireBall->DownCollision(block)) {
                FireBall->SetPosition({FireBall->GetPosition().x, block->GetPosition().y + abs(block->GetScaledSize().y / 2) + abs(FireBall->GetScaledSize().y / 2) + 10});
                FireBall->SetGravity(-4.0f);
            }
            if(FireBall->LeftCollision(block) || FireBall->RightCollision(block)) {
                FireBall->SetState(Explode);
                return;
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
void FireBallManager::FireballsInitialize() const {
    for(int i = 0; i < 3 ;i++) {
        auto temp = std::make_shared<FireBall>(Mario_->GetPosition());
        temp->SetSize({0,0});
        temp->SetWCollision(false);
        this->FireBalls.push_back(temp);
        this->renderer->AddChild(temp);
    }
}

void FireBallManager::Update() const {
    if(Mario_->GetShooting()) {
        for(const auto& Fireball : FireBalls){
            if(Fireball->GetSize().x == 0) {
                std::cout<<"Fireballs "<<std::endl;
                Fireball->SetPosition(Mario_->GetPosition());
                Fireball->SetSize({1.5,1.5});
                Fireball->SetFallingTime(Util::Time::GetElapsedTimeMs());
                Fireball->SetGravity(0);
                Fireball->SetVisible(true);
                Fireball->SetWCollision(true);
                Fireball->SetState(Roll);
                if(Mario_->GetSize().x < 0) {
                    Fireball->SetWay(Left);
                }
                else {
                    Fireball->SetWay(Right);
                }
                break;
            }
        }
        Mario_->SetShooting(false);
    }
    for (auto& fireball : FireBalls) {
        if(fireball->GetSize().x == 0) {
            continue;
        }
        if (fireball->GetState() == Roll) {
            fireball->Rolling();
            HandleBlocksCollision(fireball);
            HandleMonsterCollision(fireball);
        }
        else if (fireball->GetState() == Explode) {
            fireball->Explode(Util::Time::GetElapsedTimeMs());
        }
        else if (fireball->GetState() == End) {
            if(Util::Time::GetElapsedTimeMs() - fireball->GetStartExplodeTime() >= 700) {
                fireball->SetSize({0,0});
                fireball->SetVisible(false);
                fireball->SetDrawable(AnimationObject::GenerateAnimation(4,RESOURCE_DIR"/image/character/mario/fire/fireball/Rollingfireball",100,20));
                fireball->SetWCollision(true);
            }
        }
    }
}
