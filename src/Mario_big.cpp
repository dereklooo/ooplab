//
// Created by Benson on 2025/3/28.
//
#include "Mario/Mario_big.hpp"
Mario_big::Mario_big() : Mario(){
    this->BigDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/big/stand/stand.png")); // stand
    this->BigDrawable.push_back(this->GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/run/big_run",400,100)); //run
    this->BigDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/big/jump/big_jump.png")); //jump
    this->BigDrawable.push_back(this->GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/big/BigToSmall/big_to_small1",800,200)); // BigtoSmall
    this->BigDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/big/Down/big_down.png")); //down
    this->BigDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/big/stop/big_stop.png")); // stop
}
