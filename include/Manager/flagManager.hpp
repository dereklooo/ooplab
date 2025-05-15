//
// Created by 羅健文 on 2025/5/2.
//

#ifndef FLAGMANAGER_HPP
#define FLAGMANAGER_HPP

#include "Mario/FireBall.hpp"
#include "Mario/Mario.hpp"
#include "Object/SceneObject.hpp"
#include "Util/Renderer.hpp"
#include "Monsters/Monster.hpp"
#include "Map/Map.hpp"
#include "Block/Flag.hpp"
class FlagManager {
    public:
        FlagManager(
            std::shared_ptr<Mario>& Mario,
            std::shared_ptr<Util::Renderer>& renderer,
            std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks,
            std::shared_ptr<Map>& Background);
            void Update();
            void TouchFlag(bool flag) {
                if (flag==true) {
                    Mario_->SetTouchFlagFlag(true);
                    SetFlagMoveFlag(true);
                }

            }
            void SetFlagMoveFlag(bool flag) {FlagMoveFlag=flag;}
            bool GetFlagMoveFlag() {return FlagMoveFlag;}

            void SetMarioMoveFlag(bool flag) {MarioMoveFlag=flag;}
            bool GetMarioMoveFlag() {return MarioMoveFlag;}


    private:
        void HandleBlocksCollision() ;
        std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>& Blocks;
        bool FlagMoveFlag=false;
        bool MarioMoveFlag=false;

        std::shared_ptr<Util::Renderer>& renderer;
        std::shared_ptr<Mario>& Mario_;
        std::shared_ptr<Map>& Background;
};
#endif //FLAGMANAGER_HPP
