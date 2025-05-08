#include "Manager/BlockManager.hpp"
#include <iostream>

BlockManager::BlockManager(
    const glm::vec2 mapPos,
    const glm::vec2 mapSize,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks)
    :Blocks(Blocks), MapSize(mapSize), MapPosition(mapPos){}


void BlockManager::AddBlock(const std::shared_ptr<SceneObject>& block) const {
    (*Blocks)[block->GetType()].push_back(block);
}

void BlockManager::SetBlock(std::vector<glm::vec2> &positions, const BlockType type) const {
    for (const auto &pos : positions) {
        std::shared_ptr<SceneObject> block;
        std::cout<<MapPosition.x<<MapPosition.y<<std::endl;
        switch (type) {
            case BlockType::Lucky: block = std::make_shared<LuckyBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Original: block = std::make_shared<OriginalBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Foot: block = std::make_shared<FootBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Pipe_64_64: block = std::make_shared<Pipe64_64>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Pipe_64_96: block = std::make_shared<Pipe64_96>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Pipe_64_128: block = std::make_shared<Pipe64_128>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::LongPipe: block = std::make_shared<LongPipe>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48));break;
            case BlockType::Floor: block = std::make_shared<FloorBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Air: block = std::make_shared<AirBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Blue_Floor: block = std::make_shared<BlueFloorBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48));break;
            case BlockType::Blue_Foot: block = std::make_shared<BlueFootBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48));break;
            case BlockType::Blue_Original: block = std::make_shared<BlueOriginalBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48));break;
        }
        block->SetZIndex(100);
        block->SetSize({1.65,1.5});
        if (block) AddBlock(block);
    }
}
void BlockManager::SetFloor(std::vector<float> &Position, const float Floor_y) const{
    for(float i = 0.5f ; i <= MapSize.x / 32 ; i++) {
        bool Build = true;
        for(const float position : Position) {
            if(position == i) {
                Build = false;
            }
        }
        if(Build) {
            auto temp = std::make_shared<FloorBlock>(glm::vec2(MapPosition.x + i * 48 , MapPosition.y + Floor_y * 48));
            temp->SetSize({1.65,1.5});
            temp->SetZIndex(2);
            AddBlock(temp);

            temp = std::make_shared<FloorBlock>(glm::vec2(MapPosition.x + i * 48 , MapPosition.y + (Floor_y - 1) * 48));
            temp->SetSize({1.65,1.5});
            temp->SetZIndex(2);
            AddBlock(temp);

        }
    }
}
