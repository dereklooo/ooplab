//
// Created by benson on 2025/5/1.
//
#include "TimeAndScore/Timer.hpp"
Timer::Timer() : StillObject(RESOURCE_DIR"/image/Background/TimerandScore/0.png") {
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/0.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/1.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/2.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/3.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/4.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/5.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/6.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/7.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/8.png"));
    this->images.push_back(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/TimerandScore/9.png"));
    this->time = 0;
    this->SetZIndex(50);
}
int Timer::GetTime() const {
    return time;
}
void Timer::SetTime(const int Time) {
    switch(Time) {
        case 0:
            this->SetDrawable(this->images[0]);
        break;
        case 1:
            this->SetDrawable(this->images[1]);
        break;
        case 2:
            this->SetDrawable(this->images[2]);
        break;
        case 3:
            this->SetDrawable(this->images[3]);
        break;
        case 4:
            this->SetDrawable(this->images[4]);
        break;
        case 5:
            this->SetDrawable(this->images[5]);
        break;
        case 6:
            this->SetDrawable(this->images[6]);
        break;
        case 7:
            this->SetDrawable(this->images[7]);
        break;
        case 8:
            this->SetDrawable(this->images[8]);
        break;
        case 9:
            this->SetDrawable(this->images[9]);
        break;
        default:
            break;
    }
}
void Timer::SetOriginPosition(const glm::vec2 Pos) {
    this->originPosition = Pos;
}
glm::vec2 Timer::GetOriginPosition() const{
    return originPosition;;
}
