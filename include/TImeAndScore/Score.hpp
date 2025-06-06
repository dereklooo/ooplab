//
// Created by benson on 2025/5/20.
//

#ifndef SCORE_HPP
#define SCORE_HPP
#include <Object/StillObject.hpp>
class Score final : public StillObject{
    public:
        Score();
        void SetScore(int score);
        int GetScore() const;
    private:
        int score;
        std::vector<std::shared_ptr<Util::Image>> images;
};
#endif //SCORE_HPP
