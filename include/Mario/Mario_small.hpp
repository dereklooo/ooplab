//
// Created by Benson on 2025/3/28.
//

#ifndef MARIO_SMALL_HPP
#define MARIO_SMALL_HPP
#include "Mario.hpp"

class Mario_small : public Mario {
    public:
    enum Action {
    Run=0,
    Jump,
    Stand,
    Stop,
    SmalltoBig,
    Die
};
    using Action = Mario_small::Action;
        Mario_small();

        void SetCurrentState(int num) override;

        void Hurt() override;
        void update(std::shared_ptr<Mario> &m_MariO) override;
    private:
        std::vector<std::shared_ptr<Core::Drawable>> SmallDrawable;
};
#endif //MARIO_SMALL_HPP
