//
// Created by benson on 2025/5/1.
//

#ifndef TIMER_HPP
#define TIMER_HPP
#include "Util/Time.hpp"
class Timer {
public:
    Timer();
    float GetTime() const;
    void SetTime(float Time);
private:
    float Time = 0;
};
#endif //TIMER_HPP
