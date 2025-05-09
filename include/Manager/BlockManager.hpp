#pragma once
#include <unordered_map>
#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "Object/SceneObject.hpp"
#include "Block/LuckyBlock.hpp"
#include "Block/OriginalBlock.hpp"
#include "Block/FootBlock.hpp"
#include "Block/Pipe_64_64.hpp"
#include "Block/Pipe_64_96.hpp"
#include "Block/Pipe_64_128.hpp"
#include "Block/HorizontalPipe_64_64.hpp"
#include "Block/AirBlock.hpp"
#include "Block/FloorBlock.hpp"
#include "Block/BlueFloorBlock.hpp"
#include "Block/BlueFootBlock.hpp"
#include "Block/BlueOriginalBlock.hpp"
#include "Block/LongPipe.hpp"
class BlockManager {
public:
    BlockManager(
        glm::vec2 mapPos,
        glm::vec2 mapSize,
        std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>>& Blocks);

    void AddBlock(const std::shared_ptr<SceneObject>& block) const;
    void SetFloor(std::vector<float> &Position,float Floor_y) const;
    void SetBlock(std::vector<glm::vec2> &positions, BlockType type) const;
    void SetAnotherMap(const std::vector<glm::vec2> &positions) const;
private:
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;

    glm::vec2 MapSize;
    glm::vec2 MapPosition;
};
