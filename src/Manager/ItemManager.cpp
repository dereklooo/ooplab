//
// Created by Benson on 2025/4/26.
//

#include "Manager/ItemManager.hpp"
ItemManager::ItemManager(const glm::vec2 MapPosition,
                         const glm::vec2 MapSize,
                         std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>> &Blocks,
                         std::shared_ptr<std::unordered_map<ItemType,std::vector<std::shared_ptr<ItemObject>>>> &Items,
                         std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>> &Monsters) :
         MapSize(MapSize),
         MapPosition(MapPosition),
         Blocks(Blocks),
         Items(Items),
Monsters(Monsters){}
void ItemManager::SetItem(std::vector<glm::vec2>& Position, const ItemType type) {
    for(const auto &pos : Position) {
        for(const auto &Scene : Blocks) {
            if(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48) == Scene->GetPosition() ) {
                std::shared_ptr<ItemObject> temp = nullptr;
                switch(type) {
                    case(Item_Mushroom):
                        temp = std::make_shared<Mushroom_Item>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48));
                    break;
                    case(Item_FireFlower):

                        break;
                    case(Item_Star):

                        break;
                    case(Item_Coin):
                        temp = std::make_shared<Coin_Item>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48));
                    break;
                }
                temp->SetZIndex(100);
                temp->SetSize({1.5,1.5});
                temp->SetVisible(false);

                (*Items)[type].push_back(temp);
                Scene->SetItem(temp);
            }
        }
    }
}

void ItemManager::HandleBlockCollision(const ItemType type, const std::shared_ptr<ItemObject> &item) const {
    for (const auto& [Type,Block] : Blocks) {
        if(item->GetWCollision()) {
            switch (type) {
                case Item_Mushroom:
                    if (item->RightCollision(item)){
                        item->SetWay(Left);
                    }
                    else if( item->LeftCollision(item)) {
                        item->SetWay(Right);
                    }
                    if(item->DownCollision(Block)) {
                        item->SetPosition({item->GetPosition().x,Block->GetPosition().y + abs(Block->GetScaledSize().y / 2) + abs(item->GetScaledSize().y / 2) + 2});
                    }
                    break;
                case Item_Star:
                    if(item->DownCollision(Block)) {
                        item->SetGravity(2.0f);
                    }
                if (item->RightCollision(Block)) {
                    item->SetWay(Left);
                }
                else if (item->LeftCollision(Block)) {
                    item->SetWay(Right);
                }
                    break;
                default:
                    break;
            }
        }
    }
}
void ItemManager::HandleMonsterCollision(const std::shared_ptr<ItemObject> &item) const{
    for(auto &[type,Monster] : Monsters) {
        if(item->GetWCollision()) {
            if(item->LeftCollision(Monster)) {
                item->SetWay(Left);
            }
            if(item->RightCollision(Monster)) {
                item->SetWay(Right);
            }
        }
    }
}

void ItemManager::ItemCollision() const {
    for (const auto& [type, items] : Items) {
        for (const auto& item : items) {
            HandleBlockCollision(type, item);
            HandleMonsterCollision(item);
        }
    }
}
