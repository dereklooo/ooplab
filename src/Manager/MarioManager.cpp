//
// Created by Benson on 2025/4/26.
//
#include "Manager/MarioManager.hpp"

#include <iostream>
#include <Monsters/Turtle.hpp>
#include "Block/Flag.hpp"
#include "Block/HorizontalPipe_64_64.hpp"
#include "Monsters/Red_turtle.hpp"
#include "Monsters/Fly_turtle.hpp"
#include "Mario/Mario.hpp"


MarioManager::MarioManager(
            std::shared_ptr<Mario> &Mario,
            std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
            std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
            std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items) :
            Mario_(Mario),
            Blocks(Blocks),
            Monsters(Monsters),
            Items(Items) {
    Coin_sound->SetVolume(40);
    upGrade_sound->SetVolume(40);
    inpipe_sound->SetVolume(40);
    hitmonster_sound->SetVolume(40);
    bigjump_sound->SetVolume(40);
    smalljump_sound->SetVolume(40);
    shoot_sound->SetVolume(40);
    breakblock_sound->SetVolume(40);
            }
void MarioManager::HandleBlock() const {
    if(Mario_->GetWCollision() == false) {
        return;
    }
    for (const auto& [type, blocks] : *Blocks) {   // 注意這裡，blocks 是 vector
        for (const auto& block : blocks) {
            if(Mario_->LeftCollision(block) &&  Mario_->GetTouchFlagFlag()==false) {
                if(Mario_->GetAnimating()) {
                    if(Mario_->GetAnimationWay() == Right) {
                        Mario_->RightMove();
                    }
                    else {
                        Mario_->LeftMove();
                    }
                    if(block->GetType() == BlockType::Blue_Original) {
                        Mario_->SetWCollision(false);
                        Mario_->SetAnimation(true);
                        Mario_->SetGravity(2);
                    }
                }
                else {
                    Mario_->SetPosition({block->GetPosition().x + abs(block->GetScaledSize().x / 2) + abs(Mario_->GetScaledSize().x / 2) + 2, Mario_->GetPosition().y});
                    if(block->GetType() == BlockType::HorizontalPipe_64_64) {
                        auto temp = std::dynamic_pointer_cast<Pipe>(block);
                            if(temp->GetHasAnotherMap()){
                                Mario_->SetPosition({Mario_->GetPosition().x - 5,block->GetPosition().y});
                                Mario_->SetAnimation(true);
                                Mario_->SetAnimationWay(Left);
                                Mario_->SetCurrentState(Stand);
                                Mario_->SetCanMove(false);
                                Mario_->SetAcceleration(0.5);
                                Mario_->SetNextPosition(temp->GetNextPosition());
                                inpipe_sound->Play();
                        }

                    }
                }
            }

            else if(Mario_->RightCollision(block) &&  Mario_->GetTouchFlagFlag()==false) {
                if(Mario_->GetAnimating()) {
                    if(Mario_->GetAnimationWay() == Right) {
                        Mario_->RightMove();
                    }
                    else {
                        Mario_->LeftMove();
                    }
                    if(block->GetType() == BlockType::Blue_Original || block->GetType() == BlockType::Air) {
                        Mario_->SetWCollision(false);
                        Mario_->SetAnimation(true);
                        Mario_->SetGravity(2);
                        Mario_->SetAcceleration(0);
                    }
                }
                else {
                    Mario_->SetPosition({block->GetPosition().x - abs(block->GetScaledSize().x / 2) - abs(Mario_->GetScaledSize().x / 2) - 2, Mario_->GetPosition().y});
                    if(block->GetType() == BlockType::HorizontalPipe_64_64) {
                        auto temp = std::dynamic_pointer_cast<HorizontalPipe_64_64>(block);
                        if(temp->GetHasAnotherMap()) {
                            Mario_->SetPosition({Mario_->GetPosition().x + 5,block->GetPosition().y});
                            Mario_->SetAnimation(true);
                            Mario_->SetAnimationWay(Right);
                            Mario_->SetCurrentState(Stand);
                            Mario_->SetCanMove(false);
                            Mario_->SetAcceleration(0);
                            Mario_->SetNextPosition(temp->GetNextPosition());
                            inpipe_sound->Play();
                        }
                    }
                }
            }

            else if((Mario_->UpCollision(block) && Mario_->GetGravity() <= 0) && Mario_->GetTouchFlagFlag()==false) {
                Mario_->SetPosition({Mario_->GetPosition().x, block->GetPosition().y - abs(block->GetScaledSize().y / 2) - abs(Mario_->GetScaledSize().y / 2) - 5});
                Mario_->SetGravity(2);
                if (block->GetType() == BlockType::Lucky &&(block->GetItem()->GetType()==Item_Coins||block->GetItem()->GetType()==Item_Coin)&& block->GetGotHit()==false) {

                        Coin_sound->Play();

                }
                else if ((Mario_->GetType()==Big|| Mario_->GetType()==Fire) && (block->GetType() == BlockType::Original ||block->GetType() == BlockType::Blue_Original)) {
                    breakblock_sound->Play();
                }
                block->hit(Mario_);


                //std::cout<<Mario_->GetScore()<<std::endl;
            }
            else if(Mario_->DownCollision(block) && Mario_->GetGravity() <= 0 && (Mario_->GetTouchFlagFlag()==false ) && block->GetSize() != glm::vec2(0,0)){
                Mario_->SetPosition({Mario_->GetPosition().x, block->GetPosition().y + abs(block->GetScaledSize().y / 2) + abs(Mario_->GetScaledSize().y / 2) + 1});
                if(block->GetType() == BlockType::Pipe_64_96 || block->GetType() == BlockType::Pipe_64_128 || block->GetType() == BlockType::Pipe_64_64) {
                    auto temp = std::dynamic_pointer_cast<Pipe>(block);
                    if(temp->GetHasAnotherMap() && Mario_->GetCurrentState() == Down) {
                        Mario_->SetPosition({block->GetPosition().x,block->GetPosition().y + abs(block->GetScaledSize().y / 2) + abs(Mario_->GetScaledSize() .y / 2)});
                        Mario_->SetWCollision(false);
                        Mario_->UpDateCurrentState(Stand);
                        Mario_->SetCanMove(false);
                        Mario_->SetAnimation(true);
                        Mario_->SetGravity(0.65f);
                        Mario_->SetZIndex(1.5);
                        Mario_->SetNextPosition(temp->GetNextPosition());
                        inpipe_sound->Play();
                    }
                }
            }
        }
    }
}
void MarioManager::HandleItem() const {
    for (const auto& [type, items] : *Items) {
        for (const auto& item : items) {
            if((Mario_->LeftCollision(item)|| Mario_->RightCollision(item) || Mario_->DownCollision(item) || Mario_->UpCollision(item)) && item->GetWCollision()) {
                item->SetVisible(false);
                item->SetWCollision(false);
                item->ChangeMarioState(Mario_);
                item->SetPosition({item->GetPosition().x,item->GetPosition().y - 40000});
                Mario_->AddScore(300);
                if ((item->GetType()==ItemType::Item_OutSideCoin)) {
                    Coin_sound->Play(0);
                }
                else if (item->GetType()==ItemType::Item_Mushroom|item->GetType()==ItemType::Item_FireFlower) {
                    upGrade_sound->Play(0);
                }

            }
        }
    }
}
void MarioManager::HandleMonster(){
    for(auto &[type,monsters] : *Monsters) {
        for(auto &monster : monsters) {
            if(Mario_->GetStaring()) {
                if((Mario_->RightCollision(monster) || Mario_->LeftCollision(monster) || Mario_->DownCollision(monster) || Mario_->UpCollision(monster)) && !monster->GetDie()) {
                        monster->SetDie(true);
                        monster->SetKnockAway(true);
                        monster->SetWCollision(false);
                        monster->SetSize({monster->GetSize().x, monster->GetSize().y * -1});
                        monster->SetGravity(-10.0f);
                        Mario_->AddScore(200);
                }
                if(Util::Time::GetElapsedTimeMs() - Mario_->GetStartShiningTime() < 10000) {
                    if ((static_cast<int>(Util::Time::GetElapsedTimeMs() - Mario_->GetStartShiningTime()) / 200) % 2 == 0) {
                        Mario_->SetVisible(false);
                    } else {
                        Mario_->SetVisible(true);
                    }
                }
                else if(Util::Time::GetElapsedTimeMs() - Mario_->GetStartShiningTime() >= 10000) {
                    Mario_->SetStaring(false,0.0f);
                }
            }
            else if (Mario_->GetHurting()) {
                float elapsed = Util::Time::GetElapsedTimeMs() - Mario_->GetHurtingTime();
                if (elapsed < 1500.0f) {
                    Mario_->SetGravity(-0.75f);
                }
                else if(elapsed < 1750.0) {
                    Mario_->SetType(Small);
                }
                else if(elapsed < 1800) {
                    Mario_->SetWCollision(true);
                    Mario_->SetCanMove(true);
                    LastHurtingTime = elapsed;
                }
                else if (elapsed >= 1800.0f && elapsed <= 6500.0f) {
                    if(elapsed - LastHurtingTime <= 150.0f ) {
                        Mario_->SetVisible(true);
                    }
                    else if(elapsed - LastHurtingTime <= 300.0f ){
                        Mario_->SetVisible(false);
                    }
                    else if(elapsed - LastHurtingTime > 300.0f ) {
                        LastHurtingTime = elapsed;
                    }
                    if(Mario_->DownCollision(monster) && !monster->GetDie() && Mario_->GetGravity()>0) {
                        monster->Hurt();
                        Mario_->SetPosition({Mario_->GetPosition().x,Mario_->GetPosition().y + 10});
                        Mario_->SetGravity(-5.5f);
                    }
                }
                else {
                    Mario_->SetVisible(true);
                    Mario_->SetHurting(false, 0.0f);
                }
            }
            else {
                if((Mario_->RightCollision(monster) || Mario_->LeftCollision(monster))) {
                    switch(type) {
                        case Turtle_Type: {
                            const auto temp = std::dynamic_pointer_cast<Turtle>(monster);
                            if(temp->GetWCollision() == false) {
                                break;
                            }
                            if(temp->GetTurtleTye() == Inside) {
                                if(Mario_->RightCollision(monster)) {
                                    monster->SetWay(Right);
                                    monster->SetPosition({monster->GetPosition().x + 20,monster->GetPosition().y});
                                }
                                else if(Mario_->LeftCollision(monster)) {
                                    monster->SetWay(Left);
                                    monster->SetPosition({monster->GetPosition().x - 20,monster->GetPosition().y});
                                }
                                monster->Hurt();
                            }
                            else if(temp->GetTurtleTye() == OutSide || temp->GetTurtleTye() == Rolling){
                                Mario_->Hurt();
                            }
                            break;
                        }
                        case Red_turtle: {
                            const auto temp = std::dynamic_pointer_cast<RedTurtle>(monster);
                            std::cout << temp->GetTurtleTye() << std::endl;
                            if(temp->GetWCollision() == false) {
                                break;
                            }
                            //std::cout << temp->GetTurtleTye() << std::endl;
                            if(temp->GetTurtleTye() == Inside) {
                                if(Mario_->RightCollision(monster)) {
                                    monster->SetWay(Right);
                                    monster->SetPosition({monster->GetPosition().x + 20,monster->GetPosition().y});
                                }
                                else if(Mario_->LeftCollision(monster)) {
                                    monster->SetWay(Left);
                                    monster->SetPosition({monster->GetPosition().x - 20,monster->GetPosition().y});
                                }
                                monster->Hurt();
                            }
                            else if(temp->GetTurtleTye() == OutSide || temp->GetTurtleTye() == Rolling){
                                Mario_->Hurt();
                            }
                            break;
                        }
                        case Fly_turtle: {
                            const auto temp = std::dynamic_pointer_cast<FlyTurtle>(monster);
                            if(temp->GetWCollision() == false) {
                                break;
                            }
                            if(temp->GetTurtleTye() == Inside) {
                                if(Mario_->RightCollision(monster)) {
                                    monster->SetWay(Right);
                                    monster->SetPosition({monster->GetPosition().x + 40,monster->GetPosition().y});
                                }
                                else if(Mario_->LeftCollision(monster)) {
                                    monster->SetWay(Left);
                                    monster->SetPosition({monster->GetPosition().x - 40,monster->GetPosition().y});
                                }
                                monster->Hurt();
                            }
                            else if(temp->GetTurtleTye() == OutSide || temp->GetTurtleTye() == Rolling){
                                Mario_->Hurt();
                            }
                            break;
                        }
                        default: {
                            if(!monster->GetDie()) {
                                Mario_->Hurt();
                            }
                            break;
                        }
                    }
                }
                else if(Mario_->DownCollision(monster) && Mario_->GetGravity() > 0 && !monster->GetDie()) {
                    if(monster->GetType() == MonsterType::Kooper_Type || monster->GetType() == Eat_flower){Mario_->Hurt();}
                    else {
                        hitmonster_sound->Play();
                    }
                    monster->Hurt();

                    Mario_->AddScore(200);
                    Mario_->SetPosition({Mario_->GetPosition().x,Mario_->GetPosition().y + 10});
                    Mario_->SetGravity(-7.5f);

                }
                else if (Mario_->UpCollision(monster) ) {
                    Mario_->Hurt();
                }
            }
        }
    }
}
void MarioManager::MarioInputCtl() const {
    if(Mario_->GetCanMove() == false) {
        if(Util::Input::IsKeyDown(Util::Keycode::SPACE)) {
            //std::cout<<Mario_->GetPosition().x<<" "<<Mario_->GetPosition().y<<std::endl;
        }
        return;
    }
    if(Util::Input::IsKeyDown(Util::Keycode::SPACE)) {
        //std::cout<<Mario_->GetPosition().x<<" "<<Mario_->GetPosition().y<<std::endl;
    }
    if(Mario_->GetType() == Small) {
        if(Util::Input::IsKeyDown(Util::Keycode::Z)) {  // test
            Mario_->SetType(Fire);
        }

        if (Util::Input::IsKeyPressed(Util::Keycode::D)){
            Mario_->SetCurrentState(Run);
            Mario_->RightMove();
        }

        else if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
            Mario_->SetCurrentState(Run);
            Mario_->LeftMove();
        }
        if (Mario_->GetAcceleration()==0 && !Mario_->GetFalling()) {
            Mario_->SetCurrentState(Stand);
        }

        if(Util::Input::IsKeyPressed(Util::Keycode::W)) {
            Mario_->Jump();
            Mario_->SetCurrentState(Action::Jump);
            if(Mario_->GetFalling()==false) {
            smalljump_sound->Play();
        }

        }
        if(Util::Input::IsKeyPressed(Util::Keycode::S)) {
            Mario_->SetCurrentState(Down);
        }
    }
    else if(Mario_->GetType() == Big) {
        if (Util::Input::IsKeyPressed(Util::Keycode::D)){
            Mario_->SetCurrentState(Run);
            Mario_->RightMove();
        }
        else if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
            Mario_->SetCurrentState(Run);
            Mario_->LeftMove();
        }
        else if (Mario_->GetAcceleration()==0 && !Mario_->GetFalling()) {
            Mario_->SetCurrentState(Stand);
        }
        if(Util::Input::IsKeyDown(Util::Keycode::W)) {
            bigjump_sound->Play();
        }
        if(Util::Input::IsKeyPressed(Util::Keycode::W)) {
            Mario_->Jump();
            Mario_->SetCurrentState(Action::Jump);

        }
        if(Util::Input::IsKeyPressed(Util::Keycode::S)) {
            Mario_->SetCurrentState(Down);
            Mario_->SetAcceleration(0);
        }
    }
    else if(Mario_->GetType() == Fire) {
        if (Util::Input::IsKeyPressed(Util::Keycode::D)){
            Mario_->SetCurrentState(Run);
            Mario_->RightMove();
        }
        else if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
            Mario_->SetCurrentState(Run);
            Mario_->LeftMove();
        }
        else if (Mario_->GetAcceleration()==0 && !Mario_->GetFalling()) {
            Mario_->SetCurrentState(Stand);
        }
        if(Util::Input::IsKeyDown(Util::Keycode::W)) {
            bigjump_sound->Play();
        }
        if(Util::Input::IsKeyPressed(Util::Keycode::W)) {

            Mario_->Jump();
            Mario_->SetCurrentState(Action::Jump);




        }
        if(Util::Input::IsKeyPressed(Util::Keycode::S)) {
            Mario_->SetCurrentState(Down);
            Mario_->SetAcceleration(0);
        }
        if(Util::Input::IsKeyDown(Util::Keycode::J)) {
            Mario_->Shoot();
            shoot_sound->Play();
        }
    }

    Mario_->Brakes();
    Mario_->UpDateCurrentState(Mario_->GetCurrentState());
}
void MarioManager::MarioInitialize() const {
    Mario_->SetFallingTime(Util::Time::GetElapsedTimeMs());
    Mario_->SetPosition({-620,0});
    Mario_->UpDateCurrentState(Stand);
    Mario_->SetGravity(-2.0f);
    Mario_->SetZIndex(50);
    Mario_->SetSize({1.35,1.2});
}
void MarioManager::MarioCollision() {
    if(Mario_->GetWCollision()) {
        HandleItem();
        HandleBlock();
        this->HandleMonster();
    }
}
