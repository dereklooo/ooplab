//
// Created by Benson on 2025/4/25.
//

#ifndef ITEMMANAGER_HPP
#define ITEMMANAGER_HPP
#include <unordered_map>
#include <Monsters/Monster.hpp>

#include "Item/Coin_Item.hpp"
#include "Item/Mushroom_Item.hpp"
#include "Item/Star_Item.hpp"
#include "Object/SceneObject.hpp"
#include "Item/FireFlower_Item.hpp"
#include "Item/OutSideCoin_Item.hpp"

#include "Monsters/Monster.hpp"

class ItemManager {
    public:
        explicit ItemManager(glm::vec2 MapPosition,
            glm::vec2 MapSize,
            std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>> &Blocks,
            std::shared_ptr<std::unordered_map<ItemType,std::vector<std::shared_ptr<ItemObject>>>> &Items,
            std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>> &Monsters);

        void SetItem(std::vector<glm::vec2>& Position, ItemType type) const;

        void ItemCollision() const;

        void Update() const {
            ItemCollision();
            for(auto &[type,items] : *Items) {
                for(const auto &item : items) {
                    item->Action();
                }
            }
        }
    private:
        void HandleBlockCollision(ItemType type, const std::shared_ptr<ItemObject> &item) const;

        void HandleMonsterCollision(const std::shared_ptr<ItemObject> &item) const;

        glm::vec2 MapSize;
        glm::vec2 MapPosition;

        std::shared_ptr<std::unordered_map<ItemType,std::vector<std::shared_ptr<ItemObject>>>>& Items;
        std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>>& Monsters;
};
#endif //ITEMMANAGER_HPP
