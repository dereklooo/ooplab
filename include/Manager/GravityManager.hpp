//
// Created by benson on 2025/4/3.
//

#ifndef GRAVITYMANAGER_HPP
#define GRAVITYMANAGER_HPP
#include "Util/Time.hpp"
#include "Mario/Mario.hpp"
#include "Monsters/Monster.hpp"
class GravityManager {
    public:
        GravityManager(const std::shared_ptr<Mario> &mario,
            std::vector<std::shared_ptr<Monster>> &monsters,
            const std::vector<std::shared_ptr<SceneObject>>& Scenes) {
            this->Mario = mario;
            this->Monsters = monsters;
            this->Scenes = Scenes;
        }
        void Update(){
            Util::Time::Update();
            for(auto &object : Monsters) {
                if(IsFalling(object)) {
                    object->SetGravity(object->GetGravity() + gravity * Util::Time::GetDeltaTimeMs() / 1000);
                    object->SetFalling(true);
                }
                else {
                    object->SetGravity(0.0f);
                    object->SetFalling(false);
                }
                object->SetPosition({object->GetPosition().x,object->GetPosition().y - object->GetGravity()});
            }
            if(IsFalling(Mario)) {
                Mario->SetGravity(Mario->GetGravity() + gravity * Util::Time::GetDeltaTimeMs() / 1000);
                Mario->SetFalling(true);
            }
            else {
                Mario->SetGravity(0.0f);
                Mario->SetFalling(false);
            }
            Mario->SetPosition({Mario->GetPosition().x,Mario->GetPosition().y - Mario->GetGravity()});
        };
        bool IsFalling(const std::shared_ptr<Object> &Object) {
            for(auto &Scene : Scenes) {
                if(Object->DownCollision(Scene)) {
                    return false;
                }
            }
            return true;
        }
    private:
        const float gravity = 9.8f;
        std::shared_ptr<Util::Time> Time = std::make_shared<Util::Time>();
        std::vector<std::shared_ptr<Monster>> Monsters;
        std::vector<std::shared_ptr<SceneObject>> Scenes;
        std::shared_ptr<Mario> Mario;
        std::vector<std::shared_ptr<Object>> GravityObject;
};
#endif
//GRAVITYMANAGER_HPP
