//
// Created by benson on 2025/5/1.
//
#include "TimeAndScore/Timer.hpp"
Timer::Timer() : StillObject(RESOURCE_DIR"/image/Background/TimerandScore/0.png") {
    this->time = 0;
    this->SetZIndex(50);
}
int Timer::GetTime(){
    return time;
}
void Timer::SetTime(const float Time) {
    time = Time;
}