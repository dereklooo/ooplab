//
// Created by benson on 2025/4/3.
//

#ifndef GRAVITYMANAGER_HPP
#define GRAVITYMANAGER_HPP
#include <iostream>
#include <ostream>

#include "Util/Time.hpp"
#include "Mario/Mario.hpp"
#include "Monsters/Monster.hpp"
#include "Object/ItemObject.hpp"
#include "Object/SceneObject.hpp"

class GravityManager {
    public:
        explicit GravityManager(
            std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>>& Blocks) : Blocks(Blocks) {};
        void Update(const std::shared_ptr<Mario> &Mario,
            const std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>> &Monsters,
            const std::shared_ptr<std::unordered_map<ItemType,std::vector<std::shared_ptr<ItemObject>>>> &Items){

                this->Combination(Mario,Monsters,Items);
                for(auto &object : GravityObject) {
                    if(IsFalling(object)) {
                        const float deltaTime = (Util::Time::GetElapsedTimeMs() - object->GetFallingTime()) / 1000.0f;
                        const float gravityNow = object->GetGravity();
                        const float gravityNext = gravityNow + gravity * deltaTime;
                        object->SetGravity(gravityNext);

                        object->SetFalling(true);
                    }
                    else {
                        if(object->GetWCollision()) {
                            object->SetGravity(0.0f);
                        }
                        object->SetFalling(false);
                    }
                    object->SetFallingTime(Util::Time::GetElapsedTimeMs());
                    object->SetPosition({object->GetPosition().x,object->GetPosition().y - object->GetGravity()});
                }
            };
        void Combination(const std::shared_ptr<Mario> &mario,
            const std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>> &Monsters,
            const std::shared_ptr<std::unordered_map<ItemType,std::vector<std::shared_ptr<ItemObject>>>> &Items) {
                GravityObject.clear();
                GravityObject.push_back(mario);
                for(auto &[type,monsters] : (*Monsters)) {
                    for(auto &monster : monsters) {
                        GravityObject.push_back(monster);
                    }
                }
                for(auto &[type,items] : (*Items)) {
                    for(auto &item : items) {
                        if(item->GetState() != ItemState::Hidden) {
                            GravityObject.push_back(item);
                        }
                    }
                }
            }
        bool IsFalling(const std::shared_ptr<Object> &Object) const {
            for(auto &[type,blocks] : (*Blocks)) {
                for(auto &block : blocks) {
                    if(Object->DownCollision(block)) {
                        return false;
                    }
                }
            }
            return true;
        }
    private:
        const float gravity = 9.5f;
        std::shared_ptr<Util::Time> Time = std::make_shared<Util::Time>();
        std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::vector<std::shared_ptr<Object>> GravityObject;
};
#endif
//GRAVITYMANAGER_HPP
