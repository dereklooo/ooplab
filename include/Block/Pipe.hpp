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
        bool GetHasAnotherMap() const {
            return HasAnotherMap;
        }
    private:
        bool HasAnotherMap = false;
};
#endif //PIPE_HPP
