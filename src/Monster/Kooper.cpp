//
// Created by benson on 2025/5/27.
//
#include "Monsters/Kooper.hpp"
Kooper::Kooper(glm::vec2 position,std::shared_ptr<Mario>& Mario_) : Monster(4,RESOURCE_DIR"/image/character/monster/kooper/walk"){
    this->SetSize({3,3});
    this->Mario_ = Mario_;
    this->type = MonsterType::Kooper_Type;
    this->SetZIndex(100);
    this->SetPosition(position);
    Fireball = std::make_shared<KooperFireBall>(Mario_,this->GetPosition());
}
void Kooper::Action() {
    const float DeltaTime = Util::Time::GetElapsedTimeMs() - this->ActionTimer;
    float x = this->GetPosition().x , y = this->GetPosition().y;
    if(DeltaTime <= 1500) {
        this->SetPosition({x - 100 * Util::Time::GetDeltaTimeMs() / 1000,y});
    }
    else if(DeltaTime <= 3000) {
        this->SetPosition({x + 100 * Util::Time::GetDeltaTimeMs() / 1000,y});
    }
    else if(DeltaTime > 3000) {
        if(this->Fireball->GetPosition().x <= -840) {
            this->Fire();
        }
        this->ActionTimer = Util::Time::GetElapsedTimeMs();
    }
    if(Mario_->GetCurrentState() == Jump && this->GetGravity() == 0) {
        this->SetGravity(-5.0f);
        this->SetFallingTime(Util::Time::GetElapsedTimeMs());
    }
    if((Mario_->LeftCollision(Fireball) || Mario_->RightCollision(Fireball) || Mario_->UpCollision(Fireball) || Mario_->DownCollision(Fireball)) && Mario_->GetHurting() == false && Mario_->GetWCollision() == true) {
        Mario_->Hurt();
    }
    this->Fireball->Action();
}
void Kooper::Fire() const {
    this->Fireball->SetPosition({this->GetPosition().x,this->GetPosition().y});
}

void Kooper::Hurt() {
    (void) nullptr;
}


