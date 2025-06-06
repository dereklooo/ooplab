//
// Created by benson on 2025/5/20.
//

#ifndef TIMER_HPP
#define TIMER_HPP
#include <Object/StillObject.hpp>
#include "Util/Time.hpp"
class Timer final : public StillObject {
    public:
        explicit Timer();
        int GetTime() const;
        void SetTime(int Time);
    private:
        int time;
        std::vector<std::shared_ptr<Util::Image>> images;
};
#endif //TIMER_HPP
