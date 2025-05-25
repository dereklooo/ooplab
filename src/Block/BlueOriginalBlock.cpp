//
// Created by benson on 2025/5/8.
//
#include "BLock/BlueOriginalBlock.hpp"
BlueOriginalBlock::BlueOriginalBlock(glm::vec2 Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/BlueOriginalBlock.png",Position) {

}
void BlueOriginalBlock::ChangeState() {
    this->SetDrawable(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock_.png"));
}
void BlueOriginalBlock::hit(const std::shared_ptr<Mario> &Mario) {
    if(this->Bouncing == false && this->GotHit == false) {
        this->Bouncing = true;
        this->BouncingPos_y = this->GetPosition().y;
        this->BouncingTimer = Util::Time::GetElapsedTimeMs();
    }
    if(Item == nullptr && GotHit == false) {
        if(!Mario->GetType() == Small) {
            this->SetSize({0,0});
            this->SetVisible(false);
        }
    }
    else {
        if(this->GotHit == false) {
            this->ChangeState();
            this->Item->SetVisible(true);
            this->Item->SetState(ItemState::PoppingUp);
            this->Item->SetGravity(-10.0f);
            this->Item->SetFallingTime(Util::Time::GetElapsedTimeMs());
            this->Item->SetStartPopTime(Util::Time::GetElapsedTimeMs());
            this->GotHit = true;
        }
    }
}
