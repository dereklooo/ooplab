//
// Created by Benson on 2025/3/21.
//

#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP
#include "StillObject.hpp"
#include "Mario/Mario.hpp"
#include "Object/ItemObject.hpp"
class SceneObject : public StillObject{
    public:
        SceneObject(const std::string &path, const glm::vec2 &position) : StillObject(path) {
            this->SetPosition(position);
        }
        virtual void hit(const std::shared_ptr<Mario> &Mario) = 0;
        void SetItem(const std::shared_ptr<ItemObject> &Item) {
            this->Item = Item;
        }
        std::shared_ptr<ItemObject> GetItem() {
            return this->Item;
        };
    protected:
        bool GotHit = false;
        std::shared_ptr<ItemObject> Item = nullptr;
};
#endif //SCENEOBJECT_HPP
