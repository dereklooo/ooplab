//
// Created by Benson on 2025/4/29.
//
#include "Block/LuckyBlock.hpp"
LuckyBlock::LuckyBlock(const glm::vec2 &Position)  : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock.png",Position) {

}
void LuckyBlock::ChangeState() {
        this->SetDrawable(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock_.png"));
}
void LuckyBlock::hit(const std::shared_ptr<Mario> &Mario) {
        Mario->AddScore(200);
        if(this->Bouncing == false && this->GotHit == false){
            this->Bouncing = true;
            this->BouncingPos_y = this->GetPosition().y;
            this->BouncingTimer = Util::Time::GetElapsedTimeMs();
        }
        if(this->GotHit == false) {
                this->ChangeState();
                this->Item->SetVisible(true);
                this->Item->SetState(ItemState::PoppingUp);
                this->Item->SetGravity(-10.0f);
                this->Item->SetFallingTime(Util::Time::GetElapsedTimeMs());
                this->Item->SetStartPopTime(Util::Time::GetElapsedTimeMs());
                this->GotHit = true;
                //this->Item->SetType(null);

        }
}
