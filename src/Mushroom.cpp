//
// Created by Benson on 2025/3/20.
//
#include "Monsters/Mushroom.hpp"


void Mushroom::Action() {
	if(!Die) {
		if(this->way == Way::Left) {
			this->SetPosition({this->GetPosition().x - 1.5,this->GetPosition().y});
		}
		else if(this->way == Way::Right) {
			this->SetPosition({this->GetPosition().x + 1.5,this->GetPosition().y});
		}
	}
	else if(Util::Time::GetElapsedTimeMs() - this->DieTimer >= 1000.0f) {
			this->SetPosition({this->GetPosition().x,this->GetPosition().y-500});
	}
}
void Mushroom::Hurt() {
	this->SetDrawable(this->die->GetDrawable());
	this->Die = true;
	this->DieTimer = Util::Time::GetElapsedTimeMs();
}
