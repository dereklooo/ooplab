//
// Created by Benson on 2025/3/28.
//

#ifndef MARIO_BIG_HPP
#define MARIO_BIG_HPP
#include "Mario.hpp"
enum Action{
    Run,
    Down,
    Jump,
    BigToSmall,
    Stop,
    Stand,
 };
class Mario_big : public Mario {
    public:
        Mario_big();

        void SetCurrentState(int num) override;

        void Hurt() override;

        void update();
    private:
};
#endif //MARIO_BIG_HPP
