//
// Created by benson on 2025/5/1.
//
#include "TimeScore/Timer.hpp"
Timer::Timer() {
    this->Time = Util::Time::GetElapsedTimeMs();
}
float Timer::GetTime() const {
    return this->Time;
}
void Timer::SetTime(const float Time) {
    this->Time = Time;
}