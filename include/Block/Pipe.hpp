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
        void SetHasAnotherMap(bool B){
            HasAnotherMap = B;
        }
        bool GetHasAnotherMap() const {
            return HasAnotherMap;
        }
        glm::vec2 GetNextPosition() const {
            return next_position;
        }
    private:
        glm::vec2 next_position;
        bool HasAnotherMap = true;
};
#endif //PIPE_HPP
