//
// Created by benson on 2025/5/25.
//

#ifndef ORIGINALCOIN_HPP
#define ORIGINALCOIN_HPP
#include "Object/SceneObject.hpp"
#include "Item/Coin_Item.hpp"
class OriginalCoin : public SceneObject {
    public:
        explicit OriginalCoin(const glm::vec2 &Position);
        void ChangeState();
        void SetCoins(const std::shared_ptr<Coin_Item>& Coin_);
        void hit(const std::shared_ptr<Mario> &Mario) override;
        BlockType GetType() override{return BlockType::Lucky;}
    private:
        int Coin = 0;
        std::vector<std::shared_ptr<Coin_Item>> Coins;


};
#endif //ORIGINALCOIN_HPP
