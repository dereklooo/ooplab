//
// Created by Benson on 2025/4/25.
//

#ifndef MANAGERMANAGER_HPP
#define MANAGERMANAGER_HPP
#include "Manager/ItemManager.hpp"
#include "Manager/GravityManager.hpp"
#include "Manager/BlockManager.hpp"
#include "Manager/MarioManager.hpp"
#include "Manager/MonsterManager.hpp"
class ManagerManager {
    public:
         ManagerManager();
    private:
        std::shared_ptr<GravityManager> GravityManager;
        std::shared_ptr<BlockManager> BlockManager;
        std::shared_ptr<MarioManager> MarioManager;
        std::shared_ptr<MonsterManager> MonsterManager;
        std::shared_ptr<ItemManager> ItemManager;
};
#endif //MANAGERMANAGER_HPP
