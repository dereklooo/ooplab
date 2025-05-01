//
// Created by benson on 2025/5/1.
//

#ifndef SCORE_HPP
#define SCORE_HPP
class Score {
    public:
        Score();
        void SetScore(int score);
        int GetScore() const;
    private:
        int GameScore = 0;
};
#endif //SCORE_HPP
