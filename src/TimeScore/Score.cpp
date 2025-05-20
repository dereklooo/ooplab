//
// Created by benson on 2025/5/1.
//
#include "TImeAndScore/Score.hpp"
    Score::Score() : StillObject(RESOURCE_DIR"/image/Background/TimerandScore/0.png"){
        this->score = 0;
        this->SetZIndex(50);
}
void Score::SetScore(const int score) {
    this->score = score;
}
int Score::GetScore() const {
    return score;
}