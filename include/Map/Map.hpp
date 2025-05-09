//
// Created by Benson on 2025/5/9.
//

#ifndef MAP_HPP
#define MAP_HPP
#include "Object/StillObject.hpp"
class Map final : public StillObject {
    public:
        Map(const std::string &Path,glm::vec2 Pivot,glm::vec2 Position);
        void SetFloor(int floor);
        int GetFloor() const;
    private:
        int floor = 1;
};
#endif //MAP_HPP
