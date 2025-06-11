//
// Created by Benson on 2025/4/25.
//

#ifndef MARIOMANAGER_HPP
#define MARIOMANAGER_HPP
#include "Util/Input.hpp"
#include "Util/SFX.hpp"
#include "Mario/Mario.hpp"
#include "Monsters/Monster.hpp"
#include "Block/Pipe_64_64.hpp"
#include "Block/Pipe_64_96.hpp"
#include "Block/Pipe_64_128.hpp"
#include <iostream>
class MarioManager {
    public:
        MarioManager(
            std::shared_ptr<Mario>& Mario,
            std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
            std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters,
            std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items);
        void MarioInitialize() const;
        void MarioCollision();
        void MarioInputCtl() const;
        void Update() {
            MarioInputCtl();
            this->MarioCollision();
        };
    private:
        float LastHurtingTime = 0.0f;
        void HandleMonster();
        void HandleBlock() const;
        void HandleItem() const;
        std::shared_ptr<Mario>& Mario_;
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::shared_ptr<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>& Monsters;
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items;
    std::shared_ptr<Util::SFX> Coin_sound=std::make_shared<Util::SFX>(RESOURCE_DIR "/sound/mario_coin.mp3");
    std::shared_ptr<Util::SFX> upGrade_sound=std::make_shared<Util::SFX>(RESOURCE_DIR "/sound/super_mario_bros_mushroom_sound_effect_58k.mp3");
    std::shared_ptr<Util::SFX> inpipe_sound=std::make_shared<Util::SFX>(RESOURCE_DIR "/sound/2bm41-g8glv.mp3");
    std::shared_ptr<Util::SFX> hitmonster_sound=std::make_shared<Util::SFX>(RESOURCE_DIR "/sound/hitmonster.mp3");
    std::shared_ptr<Util::SFX> bigjump_sound=std::make_shared<Util::SFX>(RESOURCE_DIR "/sound/bigjump.mp3");
    std::shared_ptr<Util::SFX> smalljump_sound=std::make_shared<Util::SFX>(RESOURCE_DIR "/sound/smalljump.mp3");
    std::shared_ptr<Util::SFX> shoot_sound=std::make_shared<Util::SFX>(RESOURCE_DIR "/sound/fireball.mp3");
    std::shared_ptr<Util::SFX> breakblock_sound=std::make_shared<Util::SFX>(RESOURCE_DIR "/sound/breakblock.mp3");

};
#endif //MARIOMANAGER_HPP
