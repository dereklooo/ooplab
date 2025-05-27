//
// Created by Benson on 2025/5/27.
//
#include "Item/Axe.hpp"
Axe::Axe(const glm::vec2 &position) : ItemObject(position,RESOURCE_DIR"/image/character/Item/Axe.png"){

}
void Axe::Action() {
    this->SetWCollision(true);
    if(this->Collision == true){
        float DeltaTime = Util::Time::GetElapsedTimeMs() - this->StartCollision;
        if(DeltaTime <= 500) {
            Bridges[0]->SetSize({0,0});
        }
        else if(DeltaTime <= 1000) {
            Bridges[1]->SetSize({0,0});
        }
        else if(DeltaTime <= 1500) {
            Bridges[2]->SetSize({0,0});
        }
        else if(DeltaTime <= 2000) {
            Bridges[3]->SetSize({0,0});
        }
        else if(DeltaTime <= 2500) {
            Bridges[4]->SetSize({0,0});
        }
        else if(DeltaTime <= 3000) {
            Bridges[5]->SetSize({0,0});
        }
        else if(DeltaTime <= 3500) {
            Bridges[6]->SetSize({0,0});
        }
        else if(DeltaTime <= 4000) {
            Bridges[7]->SetSize({0,0});
        }
        else if(DeltaTime <= 4500) {
            Bridges[8]->SetSize({0,0});
        }
        else if(DeltaTime <= 5000) {
            Bridges[9]->SetSize({0,0});
        }
        else if(DeltaTime <= 5500) {
            Bridges[10]->SetSize({0,0});
        }
        else if(DeltaTime <= 6000) {
            Bridges[11]->SetSize({0,0});
        }
        else if(DeltaTime <= 6500) {
            Bridges[12]->SetSize({0,0});
        }
        else if(DeltaTime > 6500) {
            Mario_->SetCanMove(true);
        }
    }
}
void Axe::ChangeMarioState(std::shared_ptr<Mario> &mario) {
    Mario_ = mario;
    mario->SetCanMove(false);
    this->SetSize({0,0});
    this->StartCollision = Util::Time::GetElapsedTimeMs();
    this->Collision = true;
}
void Axe::ConnectToBlock(const std::shared_ptr<SceneObject>& block) {
    Bridges.push_back(block);
}
