//
// Created by benson on 2025/5/20.
//
#include "Manager/ElevatorManager.hpp"
ElevatorManager::ElevatorManager(std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>> &Blocks,std::shared_ptr<Mario>& Mario) : Blocks(Blocks) , Mario_(Mario){

}
void ElevatorManager::Update() const {
    for (const auto& elevator : (*Blocks)[BlockType::Elevator_Down]) {
        const auto temp = std::dynamic_pointer_cast<Elevator>(elevator);
        temp->Move();
        if(Mario_->DownCollision(temp)) {
            Mario_->SetPosition({Mario_->GetPosition().x,Mario_->GetPosition().y - 1.5});
        }
    }
    for (const auto& elevator : (*Blocks)[BlockType::Elevator_Up]) {
        const auto temp = std::dynamic_pointer_cast<Elevator>(elevator);
        temp->Move();
        if(Mario_->DownCollision(temp)) {
            Mario_->SetPosition({Mario_->GetPosition().x,Mario_->GetPosition().y + 1.5});
        }
    }

}
