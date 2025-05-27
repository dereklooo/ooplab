//
// Created by benson on 2025/3/17.
//

#ifndef KOOPER_HPP
#define KOOPER_HPP
#include "Monster.hpp"
#include "Trap/KooperFireBall.hpp"
#include "Mario/Mario.hpp"
class Kooper : public Monster {
    public:
        explicit Kooper(glm::vec2 position,std::shared_ptr<Mario>& Mario_);
        std::shared_ptr<KooperFireBall> GetFireBall(){return Fireball;};
        void Action() override;
        void Hurt() override;
        void Fire() const;
    private:
        float ActionTimer = Util::Time::GetElapsedTimeMs();
        std::shared_ptr<Mario> Mario_;
        std::shared_ptr<KooperFireBall> Fireball;
};
#endif //KOOPER_HPP
