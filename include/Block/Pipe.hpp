//
// Created by Benson on 2025/4/29.
//

#ifndef PIPE_HPP
#define PIPE_HPP
#include "Object/SceneObject.hpp"
class Pipe : public SceneObject {
    public:
        Pipe(const std::string& Path, const glm::vec2 position) : SceneObject(Path,position) {

        };
        void SetHasAnotherMap(const bool B){
            HasAnotherMap = B;
        }
        bool GetHasAnotherMap() const {
            return HasAnotherMap;
        }
        void SetNextPipPosition(const glm::vec2 pos) {
                this->next_position = pos;
        }
        glm::vec2 GetNextPosition() const {
            return next_position;
        }
    private:
        bool HasAnotherMap = false;
        glm::vec2 next_position;
};
#endif //PIPE_HPP
