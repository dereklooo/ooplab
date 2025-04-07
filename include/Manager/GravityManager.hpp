//
// Created by benson on 2025/4/3.
//

#ifndef GRAVITYMANAGER_HPP
#define GRAVITYMANAGER_HPP
#include "Util/Time.hpp"
#include "Object/Object.hpp"

class GravityManager {
    public:
        void Update(std::shared_ptr<Object> &Object){
            Util::Time::Update();
            if(time <= 0) {
                time -= Util::Time::GetDeltaTimeMs();
                Object->SetPosition({Object->GetPosition().x,Object->GetPosition().y -gravity});
                time = 1000.0f;
            }
        };
        void SetGravity(float Number) {
            time = Number;
        }
    private:
        const float gravity = 9.8f;
        float time = 1000.0f;
        std::shared_ptr<Util::Time> Time = std::make_shared<Util::Time>();
};
//GRAVITYMANAGER_HPP
