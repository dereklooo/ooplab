//
// Created by Benson on 2025/5/9.
//
#include "Map/Map.hpp"
Map::Map(const std::string &Path, const glm::vec2 Pivot, const glm::vec2 Position) : StillObject(Path){
    this->SetPosition(Position);
    this->SetPivot(Pivot);
    this->SetSize({1.5,1.5});
    this->SetZIndex(1);
}
int Map::GetFloor() const {
    return this->floor;
}
void Map::SetFloor(const int floor) {
    this->floor = floor;
}

