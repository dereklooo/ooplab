//
// Created by Benson on 2025/3/21.
//

#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP
#include "StillObject.hpp"
#include "Mario/Mario.hpp"
#include "Object/ItemObject.hpp"
enum class BlockType {
    Lucky,
    Original,
    Foot,
    Pipe_64_64,
    Pipe_64_96,
    Pipe_64_128,
    LongPipe,
    HorizontalPipe_64_64,
    Floor,
    Blue_Floor,
    Blue_Foot,
    Blue_Original,
    Air,

};

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
        BlockType virtual GetType() = 0;
    protected:
        bool GotHit = false;
        std::shared_ptr<ItemObject> Item = nullptr;
};
#endif //SCENEOBJECT_HPP
