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

            GravityObject.push_back(mario);
            for (const auto &monster : monsters) {
                GravityObject.push_back(monster);
            }
            this->Scenes = Scenes;
        }
        void Update(){
            Util::Time::Update();
            if(time <= 0) {
                time -= Util::Time::GetDeltaTimeMs();
               // Object->SetPosition({Object->GetPosition().x,Object->GetPosition().y -gravity});
                time = 1000.0f;
            }
        };
        bool Isfalling() {
            for(auto object : GravityObject) {
              //  if(object->)
            }
        }
        void SetGravity(float Number) {
            time = Number;
        }
    private:
        const float gravity = 9.8f;
        float time = 1000.0f;
        std::shared_ptr<Util::Time> Time = std::make_shared<Util::Time>();
        std::vector<std::shared_ptr<Object>> GravityObject;
        std::vector<std::shared_ptr<SceneObject>> Scenes;
};
#endif
//GRAVITYMANAGER_HPP
