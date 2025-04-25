//
// Created by Benson on 2025/4/25.
//

#ifndef ITEMMANAGER_HPP
#define ITEMMANAGER_HPP
#include <unordered_map>
#include "Item/Coin_Item.hpp"
#include "Item/Mushroom_Item.hpp"
#include "Object/SceneObject.hpp"

class ItemManager {
    public:
        ItemManager(std::vector<std::shared_ptr<SceneObject>>& SceneObjects);
        void SetItem() {

        }
    private:
        std::unordered_map<ItemType,std::pmr::vector<std::shared_ptr<ItemObject>>> ItemMap;
        std::vector<std::shared_ptr<ItemObject>> &AllItems;
        std::vector<std::shared_ptr<SceneObject>> &SceneObjects;
};
#endif //ITEMMANAGER_HPP
