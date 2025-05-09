//
// Created by benson on 2025/5/2.
//
#ifndef FIREBALLMANAGER_HPP
#define FIREBALLMANAGER_HPP
#include "Mario/FireBall.hpp"
#include "Mario/Mario.hpp"
#include "Object/SceneObject.hpp"
#include "Util/Renderer.hpp"
#include "Monsters/Monster.hpp"

class FireBallManager {
    public:
        FireBallManager(
            std::shared_ptr<Mario>& Mario,
            std::shared_ptr<Util::Renderer>& renderer,
            std::vector<std::shared_ptr<FireBall>>& Fireballs,
            std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
            std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters);
            void Update() const;
            void FireballsInitialize() const;
    private:
        void HandleMonsterCollision(const std::shared_ptr<FireBall> &FireBall) const;
        void HandleBlocksCollision(const std::shared_ptr<FireBall> &FireBall) const;
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters;

        std::vector<std::shared_ptr<FireBall>>& FireBalls;
        std::shared_ptr<Util::Renderer>& renderer;
        std::shared_ptr<Mario>& Mario_;
};
#endif //FIREBALLMANAGER_HPP
