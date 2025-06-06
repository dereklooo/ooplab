//
// Created by benson on 2025/5/26.
//
#include "Trap/TrapFireBall.hpp"
#include <cmath>

#include "Util/Time.hpp"

TrapFireBall::TrapFireBall(glm::vec2 center, const float Radius) : AnimationObject(4,RESOURCE_DIR"/image/Background/Level4/Block/TrapFireball"){
    this->Radius = Radius;
    this->Center = center;
}
void TrapFireBall::Rotate() {
    constexpr double PI = 3.141592653589793;
    AngleDegrees += 75 * Util::Time::GetDeltaTimeMs() / 1000;
    AngleRad = AngleDegrees * PI / 180.0;
    const double x = Center.x + Radius * cos(AngleRad);
    const double y = Center.y + Radius * sin(AngleRad);
    this->SetPosition(glm::vec2(x, y));
}

