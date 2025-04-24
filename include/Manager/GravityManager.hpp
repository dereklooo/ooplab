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
class GravityManager {
    public:
        explicit GravityManager(const std::vector<std::shared_ptr<SceneObject>>& Scenes) {
            this->Scenes = Scenes;
        };
        void Update(const std::shared_ptr<Mario> &mario,
            const std::vector<std::shared_ptr<Monster>> &monsters,
            const std::vector<std::shared_ptr<ItemObject>> &items){

                this->Combination(mario,monsters,items);
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
            const std::vector<std::shared_ptr<Monster>> &monsters,
            const std::vector<std::shared_ptr<ItemObject>> &items) {
                GravityObject.clear();
                GravityObject.push_back(mario);
                for(auto &Monster : monsters) {
                    GravityObject.push_back(Monster);
                }
                for(auto &item : items) {
                    if(item->GetState() != ItemState::Hidden) {
                        GravityObject.push_back(item);
                    }
                }
            }
        bool IsFalling(const std::shared_ptr<Object> &Object) {
            for(auto &Scene : Scenes) {
                if(Object->DownCollision(Scene)) {
                    return false;
                }
            }
            return true;
        }
    private:
        const float gravity = 9.5f;
        std::shared_ptr<Util::Time> Time = std::make_shared<Util::Time>();
        std::vector<std::shared_ptr<SceneObject>> Scenes;
        std::vector<std::shared_ptr<Object>> GravityObject;
};
#endif
//GRAVITYMANAGER_HPP
