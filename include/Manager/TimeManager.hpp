//
// Created by Benson on 2025/3/29.
//

#ifndef TIMEMANAGER_HPP
#define TIMEMANAGER_HPP
#include "Util/Time.hpp"
#include "Util/GameObject.hpp"
class TimeManager {
    public:
        void gravity(std::shared_ptr<Util::GameObject> &object) {
            const float GravityNum = 9.81f;

        }
        void Pause() {

        }
    void updata() {
            Util::Time::Update();
            float Time;

        }
    private:
};
#endif //TIMEMANAGER_HPP
