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
        explicit GravityManager(const std::vector<std::shared_ptr<SceneObject>>& Scenes) {
            this->Scenes = Scenes;
        };
        void Update(const std::shared_ptr<Mario> &mario,
            const std::vector<std::shared_ptr<Monster>> &monsters){
                Util::Time::Update();
                this->Combination(mario,monsters);
                for(auto &object : GravityObject) {
                    if(IsFalling(object)) {
                        object->SetGravity(object->GetGravity() + gravity * Util::Time::GetDeltaTimeMs() / 1000); //1 -> 0.004s = 4ms    ,  9.8 M/ms
                        object->SetFalling(true);
                    }
                    else {
                        object->SetGravity(0.0f);
                        object->SetFalling(false);
                    }
                    object->SetPosition({object->GetPosition().x,object->GetPosition().y - object->GetGravity()});
                }
            };
    void Combination(const std::shared_ptr<Mario> &mario,
        const std::vector<std::shared_ptr<Monster>> &monsters) {
            GravityObject.clear();
            GravityObject.push_back(mario);
            for(auto &Monster : monsters) {
                GravityObject.push_back(Monster);
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
        const float gravity = 50.0f;
        std::shared_ptr<Util::Time> Time = std::make_shared<Util::Time>();
        std::vector<std::shared_ptr<SceneObject>> Scenes;
        std::vector<std::shared_ptr<Object>> GravityObject;
};
#endif
//GRAVITYMANAGER_HPP
