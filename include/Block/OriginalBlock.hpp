//
// Created by benson on 2025/3/25.
//

#ifndef ORIGINALBLOCK_HPP
#define ORIGINALBLOCK_HPP
#include "Object/SceneObject.hpp"
#include "Util/Time.hpp"
class OriginalBlock : public SceneObject {
    public:
    OriginalBlock(glm::vec2 Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/OriginalBlock.png",Position) {

    }
    void ChangeState() {
        this->SetDrawable(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/Level1/Block/LuckyBlock_.png"));
    }
    void hit(const std::shared_ptr<Mario> &Mario) override {
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
    BlockType GetType() override {return BlockType::Original;};
    private:
        float BouncingTimer = 0;
        bool Bouncing = false;
        std::shared_ptr<Util::Time> time;
};
#endif //ORIGINALBLOCK_HPP
