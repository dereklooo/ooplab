//
// Created by Benson on 2025/4/25.
//

#ifndef MANAGERMANAGER_HPP
#define MANAGERMANAGER_HPP
#include "Manager/ElevatorManager.hpp"
#include "Manager/MapManager.hpp"
#include "Manager/ItemManager.hpp"
#include "Manager/GravityManager.hpp"
#include "Manager/BlockManager.hpp"
#include "Manager/MarioManager.hpp"
#include "Manager/MonsterManager.hpp"
#include "Manager/FireBallManager.hpp"
#include "Manager/FlagManager.hpp"
#include "Manager/TImeScoreManager.hpp"
#include "Manager/TrapFireBallManager.hpp"
#include "Object/SceneObject.hpp"

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
            FlagManager_= std::make_shared<FlagManager>(Mario,Renderer,Blocks,Background);
            ElevatorManager_ = std::make_shared<ElevatorManager>(Blocks,Mario);
            TimeScoreManager_ = std::make_shared<TimeScoreManager>(Mario,Util::Time::GetElapsedTimeMs());
            TrapFireBallManager_ = std::make_shared<TrapFireBallManager>(Mario,Background->GetPosition(),Background->GetScaledSize());
    };
    void SetBlock(std::vector<glm::vec2> &positions, const BlockType type) const{
        BlockManager_->SetBlock(positions, type);
    }
    void SetElevator(const glm::vec2 positions, const int MoveLong,Way way) const{
        BlockManager_->SetElevator(positions,MoveLong,way);
    }
    void SetFloor(const std::vector<glm::vec2>& Position,const std::vector<glm::vec2>& Size) const {
        BlockManager_->SetFloor(Position,Size);
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
    void TimeScoreManagerInitialize(const std::shared_ptr<Util::Renderer> &renderer) const{
        TimeScoreManager_->TimeScoreManagerInitialize(renderer);
    }
    void FireballsInitialize() const {
        FireBallManager_->FireballsInitialize();
    }
    void SetAnotherMap(const std::vector<glm::vec2> &positions,const std::vector<glm::vec2> &positions_) const {
        BlockManager_->SetAnotherMap(positions,positions_);
    }
    void SetFireball(const std::vector<glm::vec2>& Positions, const std::shared_ptr<Util::Renderer>& Render) {
        TrapFireBallManager_->SetFireball(Positions,Render);
    }
    void Update() const{
        MarioManager_->Update();
        FlagManager_->Update();
        BlockManager_->Update();
        ItemManager_->Update();
        MonsterManager_->Update();
        GravityManager_->Update();
        TrapFireBallManager_->Update();
        MapManager_->Update();
        FireBallManager_->Update();
        ElevatorManager_->Update();
        TimeScoreManager_->Update();
        std::cout<< Background->GetPosition().x << ' '<< Background->GetPosition().y << " damario "<< Mario->GetPosition().x<< ' '<< Mario->GetPosition().y << std::endl;

    }


    private:
        std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>& Items;
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::vector<std::shared_ptr<FireBall>>& FireBalls;
        std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>>& Monsters;
        std::shared_ptr<Map>& Background;
        std::shared_ptr<Util::Renderer>& Renderder_;
        std::shared_ptr<Mario>& Mario;
        std::shared_ptr<FlagManager> FlagManager_;
        std::shared_ptr<MapManager> MapManager_;
        std::shared_ptr<GravityManager> GravityManager_;
        std::shared_ptr<BlockManager> BlockManager_;
        std::shared_ptr<MarioManager> MarioManager_;
        std::shared_ptr<MonsterManager> MonsterManager_;
        std::shared_ptr<ItemManager> ItemManager_;
        std::shared_ptr<FireBallManager> FireBallManager_;
        std::shared_ptr<ElevatorManager> ElevatorManager_;
        std::shared_ptr<TimeScoreManager> TimeScoreManager_;
        std::shared_ptr<TrapFireBallManager> TrapFireBallManager_;

};
#endif //MANAGERMANAGER_HPP
