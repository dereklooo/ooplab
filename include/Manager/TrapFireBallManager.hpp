//
// Created by benson on 2025/5/26.
//

#ifndef TRAPFIREBALLMANAGER_HPP
#define TRAPFIREBALLMANAGER_HPP
#include "Trap/TrapFireBall.hpp"
#include "Mario/Mario.hpp"
#include "Util/Renderer.hpp"

class TrapFireBallManager {
    public:
    explicit TrapFireBallManager(std::shared_ptr<Mario>& Mario,glm::vec2 mapPos,glm::vec2 mapSize);
        void SetFireball(const std::vector<glm::vec2>& Positions, const std::shared_ptr<Util::Renderer>& Render);
        void Update();
    private:
        void HandleMarioCollision();
        const glm::vec2 mapPos;
        const glm::vec2 mapSize;
        std::shared_ptr<Mario>& Mario_;
        std::vector<std::shared_ptr<TrapFireBall>> Fireballs;
};
#endif //TRAPFIREBALLMANAGER_HPP
