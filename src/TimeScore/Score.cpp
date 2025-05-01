//
// Created by benson on 2025/5/1.
//
#include "TimeScore/Score.hpp"
Score::Score() {
    this->GameScore = 0;
}
void Score::SetScore(const int score) {
        GameScore = score;
}
int Score::GetScore() const {
    return GameScore;
}