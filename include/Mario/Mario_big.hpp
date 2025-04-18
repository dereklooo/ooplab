//
// Created by Benson on 2025/3/28.
//

#ifndef MARIO_BIG_HPP
#define MARIO_BIG_HPP
#include "Mario.hpp"

class Mario_big : public Mario {
    public:
    enum Action{
        Run=0,
        Jump,
        Stand,
        Stop,
        Down,
        BigToSmall
     };
    using Action = Mario_big::Action;
        Mario_big();

        void UpDateCurrentState(int num) override;

        void Hurt() override;

        void update() override;
    private:
};
#endif //MARIO_BIG_HPP
