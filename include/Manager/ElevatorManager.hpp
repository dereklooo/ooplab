//
// Created by benson on 2025/5/20.
//

#ifndef ELEVATORMANAGER_HPP
#define ELEVATORMANAGER_HPP
#include "Block/Elevator.hpp"

class ElevatorManager{
    public:
        explicit ElevatorManager(std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>> &Blocks,std::shared_ptr<Mario>& Mario);
        void Update() const;
    private:
        std::shared_ptr<std::unordered_map<BlockType,std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        std::shared_ptr<Mario>& Mario_;
};
#endif //ELEVATORMANAGER_HPP
