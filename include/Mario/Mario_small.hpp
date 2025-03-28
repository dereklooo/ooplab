//
// Created by Benson on 2025/3/28.
//

#ifndef MARIO_SMALL_HPP
#define MARIO_SMALL_HPP
#include "Mario.hpp"
enum Action {
    Run,
    Jump,
    SmalltoBig,
    Die,
    Stop,
    Stand
};
class Mario_small : public Mario {
    public:
        Mario_small();

        void SetCurrentState(int num) override;

        void Hurt() override;
    private:
        std::vector<std::shared_ptr<Core::Drawable>> SmallDrawable;
};
#endif //MARIO_SMALL_HPP
