#include "Manager/BlockManager.hpp"

BlockManager::BlockManager(const glm::vec2 mapPos, const glm::vec2 mapSize, std::vector<std::shared_ptr<SceneObject>> &sceneObjects)
    : MapSize(mapSize), MapPosition(mapPos), SceneObjects(sceneObjects) {}

void BlockManager::AddBlock(const std::shared_ptr<SceneObject>& block) {
    BlockMap[block->GetType()].push_back(block);
    SceneObjects.push_back(block); // 加進碰撞處理場景中
}

void BlockManager::SetBlock(std::vector<glm::vec2> &positions, const BlockType type) {
    for (const auto &pos : positions) {
        std::shared_ptr<SceneObject> block;

        switch (type) {
            case BlockType::Lucky: block = std::make_shared<LuckyBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Original: block = std::make_shared<OriginalBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Foot: block = std::make_shared<FootBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Pipe_64_64: block = std::make_shared<Pipe64_64>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Pipe_64_96: block = std::make_shared<Pipe64_96>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Pipe_64_128: block = std::make_shared<Pipe64_128>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
            case BlockType::Air: block = std::make_shared<AirBlock>(glm::vec2(MapPosition.x + pos.x * 48 , MapPosition.y + pos.y * 48)); break;
        }
        block->SetZIndex(100);
        block->SetSize({1.5,1.5});
        if (block) AddBlock(block);
    }
}
void BlockManager::SetFloor(std::vector<std::shared_ptr<SceneObject>>& SceneManager,std::vector<float> &Position, const float Floor_y){
    for(float i = 0.5f ; i <= MapSize.x / 32 ; i++) {
        bool Build = true;
        for(const float position : Position) {
            if(position == i) {
                Build = false;
            }
        }
        if(Build) {
            auto temp = std::make_shared<AirBlock>(glm::vec2(MapPosition.x + i * 48 , MapPosition.y + Floor_y * 48));
            temp->SetSize({1.5,1.5});
            temp->SetZIndex(100);
            AddBlock(temp);

            temp = std::make_shared<AirBlock>(glm::vec2(MapPosition.x + i * 48 , MapPosition.y + (Floor_y - 1) * 48));
            temp->SetSize({1.5,1.5});
            temp->SetZIndex(100);
            AddBlock(temp);

        }
    }
}

std::vector<std::shared_ptr<SceneObject>> BlockManager::GetByType(const BlockType type) {
    return BlockMap[type];
}
