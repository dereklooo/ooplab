//
// Created by benson on 2025/5/25.
//
#include "Block/OriginalCoin.hpp"
OriginalCoin::OriginalCoin(const glm::vec2 &Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/OriginalBlock.png",Position){
    SetItem(std::make_shared<Coin_Item>(glm::vec2({999,999})));
}


void OriginalCoin::SetCoins(const std::shared_ptr<Coin_Item>& Coin_) {
    Coins.push_back(Coin_);
    this->Coin += 1;
}

void OriginalCoin::ChangeState() {
    this->SetDrawable(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock_.png"));
}
void OriginalCoin::hit(const std::shared_ptr<Mario> &Mario) {
    if(this->Bouncing == false && this->GotHit == false) {
        this->Bouncing = true;
        this->BouncingPos_y = this->GetPosition().y;
        this->BouncingTimer = Util::Time::GetElapsedTimeMs();
    }
    if(Coin > 0) {
        if(this->GotHit == false) {
            this->Coins[Coin-1]->SetVisible(true);
            this->Coins[Coin-1]->SetState(ItemState::PoppingUp);
            this->Coins[Coin-1]->SetGravity(-20.0f);
            this->Coins[Coin-1]->SetPosition(this->GetPosition());
            this->Coins[Coin-1]->SetFallingTime(Util::Time::GetElapsedTimeMs());
            this->Coins[Coin-1]->SetStartPopTime(Util::Time::GetElapsedTimeMs());
            Coin -= 1;
        }
        if(Coin == 0){
            this->ChangeState();
            this->GotHit = true;
        }
    }
}