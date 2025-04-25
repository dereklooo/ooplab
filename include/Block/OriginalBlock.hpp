//
// Created by benson on 2025/3/25.
//

#ifndef ORIGINALBLOCK_HPP
#define ORIGINALBLOCK_HPP
#include "Object/SceneObject.hpp"
#include "Util/Time.hpp"
class OriginalBlock : public SceneObject {
    public:
    OriginalBlock(glm::vec2 Position) : SceneObject(RESOURCE_DIR"/image/Background/Level1/Block/OriginalBlock.png",Position) {

    }
    void hit(const std::shared_ptr<Mario> &Mario) override {
        if(!Mario->GetType() == Small) {
            this->SetSize({0,0});
            this->SetVisible(false);
        }
    }
    BlockType GetType() override {return BlockType::Original;};
    private:
        float BouncingTimer = 0;
        bool Bouncing = false;
        std::shared_ptr<Util::Time> time;
};
#endif //ORIGINALBLOCK_HPP
