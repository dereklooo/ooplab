//
// Created by benson on 2025/5/26.
//
#include "Manager/TrapFireBallManager.hpp"

#include <iostream>
#include <ostream>


TrapFireBallManager::TrapFireBallManager(std::shared_ptr<Mario>& Mario,const glm::vec2 mapPos,const glm::vec2 mapSize) : mapPos(mapPos) , mapSize(mapSize),Mario_(Mario) {

}
void TrapFireBallManager::Update(){
    for (const auto &Fireball : Fireballs) {
        Fireball->Rotate();
    }
    HandleMarioCollision();
    if (Mario_->GetPosition().x >= 0) {
        for(const auto &fireball : Fireballs) {
            fireball->SetPosition({fireball->GetPosition().x - 4, fireball->GetPosition().y});
            fireball->SetCenter({fireball->GetCenter().x-4,fireball->GetCenter().y});
        }
    }
}
void TrapFireBallManager::SetFireball(const std::vector<glm::vec2>& Positions, const std::shared_ptr<Util::Renderer>& Render) {
    for(auto &pos : Positions) {
        for(float i = 0.0; i <= 6 ;i += 1.0f) {
            std::cout << i << std::endl;
            auto temp = std::make_shared<TrapFireBall>(glm::vec2(mapPos.x + pos.x * 48, mapPos.y + pos.y * 48),i * 20);
            temp->SetSize({2.5,2.5});
            temp->SetZIndex(50);
            Render->AddChild(temp);
            Fireballs.push_back(temp);
        }
    }
}
void TrapFireBallManager::HandleMarioCollision() {
    for (auto &Fireball : Fireballs) {
        if((Mario_->LeftCollision(Fireball) || Mario_->RightCollision(Fireball) || Mario_->UpCollision(Fireball) || Mario_->DownCollision(Fireball)) && Mario_->GetHurting() == false && Mario_->GetAnimating() == false) {
            Mario_->Hurt();
        }
    }
}