//
// Created by Benson on 2025/3/21.
//

#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP
#include "StillObject.hpp"
class ScenceObject : public StillObject{
    public:
        ScenceObject(std::string path,glm::vec2 position) : StillObject(path) {
            this->SetPosition(position);
        }

    private:
};
#endif //SCENEOBJECT_HPP
