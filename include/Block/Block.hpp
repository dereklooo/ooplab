//
// Created by benson on 2025/4/10.
//

#ifndef BLOCK_HPP
#define BLOCK_HPP
#include "Object/SceneObject.hpp"
#include "Mario/Mario.hpp"
class Block : public SceneObject {
    public:
        Block(const std::string &path,const glm::vec2 &position) : SceneObject(path,position) {};
        void virtual hit(std::shared_ptr<Mario> Mario) = 0;

};
#endif //BLOCK_HPP
