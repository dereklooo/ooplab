//
// Created by Benson on 2025/4/25.
//

#ifndef MANAGERMANAGER_HPP
#define MANAGERMANAGER_HPP
#include "Manager/MapManager.hpp"
#include "Manager/ItemManager.hpp"
#include "Manager/GravityManager.hpp"
#include "Manager/BlockManager.hpp"
#include "Manager/MarioManager.hpp"
#include "Manager/MonsterManager.hpp"
#include "Manager/FireBallManager.hpp"
class ManagerManager {
    public:
    ManagerManager(
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>> &Items,
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>> &Blocks,
        std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>> &Monsters,
        std::vector<std::shared_ptr<FireBall>>& FireBalls,
        std::shared_ptr<Mario> &Mario,
        std::shared_ptr<Util::Renderer>& Renderer,
        std::shared_ptr<Map> &Background) :
        Items(Items),
        Blocks(Blocks),
        FireBalls(FireBalls),
        Monsters(Monsters),
        Background(Background),
        Renderder_(Renderer),
        Mario(Mario){
            GravityManager_ = std::make_shared<GravityManager>(Mario,FireBalls,Blocks,Monsters,Items);
            BlockManager_ = std::make_shared<BlockManager>(Background->GetPosition(), Background->GetScaledSize(),Blocks);
            MarioManager_ = std::make_shared<MarioManager>(Mario,Blocks,Monsters,Items);
            MonsterManager_ = std::make_shared<MonsterManager>(Monsters, Blocks);
            ItemManager_ = std::make_shared<ItemManager>(Background->GetPosition(), Background->GetScaledSize(),Blocks,Items,Monsters);
            MapManager_ = std::make_shared<MapManager>(Mario,Background,FireBalls,Blocks,Monsters,Items);
            FireBallManager_ = std::make_shared<FireBallManager>(Mario,Renderer,FireBalls,Blocks,Monsters);
    };
    void SetBlock(std::vector<glm::vec2> &positions, const BlockType type) const{
        BlockManager_->SetBlock(positions, type);
    }
    void SetFloor(std::vector<float> &Position, const float Floor_y) const {
        BlockManager_->SetFloor(Position,Floor_y);
    }
    void SetItem(std::vector<glm::vec2>& Position, const ItemType type) const{
        ItemManager_->SetItem(Position, type);
    }
    void AddMonster(const std::vector<std::shared_ptr<Monster>>& monsters, const std::shared_ptr<Util::Renderer> &renderer) const {
        MonsterManager_->AddMonster(monsters, renderer);
    };
    void MarioInitialize() const {
        MarioManager_->MarioInitialize();
    }
    void FireballsInitialize() const {
        FireBallManager_->FireballsInitialize();
    }
    void SetAnotherMap(const std::vector<glm::vec2> &positions) const {
        BlockManager_->SetAnotherMap(positions);
    }
    void Update() const{
        ItemManager_->Update();
        MonsterManager_->Update();
        GravityManager_->Update();
        MapManager_->Update();
        MarioManager_->Update();
        FireBallManager_->Update();
    }


    private:
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items;
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::vector<std::shared_ptr<FireBall>>& FireBalls;
        std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>>& Monsters;
        std::shared_ptr<Map>& Background;
        std::shared_ptr<Util::Renderer>& Renderder_;
        std::shared_ptr<Mario>& Mario;

        std::shared_ptr<MapManager> MapManager_;
        std::shared_ptr<GravityManager> GravityManager_;
        std::shared_ptr<BlockManager> BlockManager_;
        std::shared_ptr<MarioManager> MarioManager_;
        std::shared_ptr<MonsterManager> MonsterManager_;
        std::shared_ptr<ItemManager> ItemManager_;
        std::shared_ptr<FireBallManager> FireBallManager_;

};
#endif //MANAGERMANAGER_HPP
