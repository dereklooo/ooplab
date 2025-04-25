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
#include "Block/AirBlock.hpp"

class BlockManager {
public:
    BlockManager(glm::vec2 mapPos, glm::vec2 mapSize, std::vector<std::shared_ptr<SceneObject>> &sceneObjects);

    void AddBlock(const std::shared_ptr<SceneObject>& block);
    void SetFloor(std::vector<std::shared_ptr<SceneObject>>& SceneManager,std::vector<float> &Position, const float Floor_y);
    void SetBlock(std::vector<glm::vec2> &positions, BlockType type);

    std::vector<std::shared_ptr<SceneObject>> GetByType(BlockType type);

private:
    std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>> BlockMap;

    glm::vec2 MapSize;
    glm::vec2 MapPosition;
    std::vector<std::shared_ptr<SceneObject>> &SceneObjects;
};
