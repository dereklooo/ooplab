//
// Created by Benson on 2025/3/21.
//

#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP
#include "StillObject.hpp"
#include "Mario/Mario.hpp"
#include "Item/Mushroom_Item .hpp"
class SceneObject : public StillObject{
    public:
        SceneObject(std::string path,glm::vec2 position) : StillObject(path) {
            this->SetPosition(position);
        }
        virtual void hit(const std::shared_ptr<Mario> &Mario) = 0;
    private:
        std::shared_ptr<ItemObject> Item;
};
#endif //SCENEOBJECT_HPP
