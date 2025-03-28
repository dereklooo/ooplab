//
// Created by Benson on 2025/3/28.
//
#include "Mario/Mario_small.hpp"
Mario_small::Mario_small() : Mario(){
    this->SmallDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/small/stand/small_stand.png")); // stand
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/small/run/small_run",400,100)); //run
    this->SmallDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/small/jump/small_jump.png")); // jump
    this->SmallDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/small/die/die.png")); // die
    this->SmallDrawable.push_back(Mario_small::GenerateAnimation(3,RESOURCE_DIR"/image/character/mario/small/SmalltoBig/SmalltoBig",800,200)); //smalltobig
    this->SmallDrawable.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/character/mario/small/stop/small_stop.png"));
}
void Mario_small::Hurt() {

}
void Mario_small::SetCurrentState(int num) {
    switch(num) {
        case 1:

            break;
    }

}
