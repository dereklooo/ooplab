//
// Created by Benson on 2025/3/20.
//
#include "Monsters/Mushroom.hpp"
void Mushroom::Action() {
	if(this->way == Way::Left) {
		this->SetPosition({this->GetPosition().x - 1.5,this->GetPosition().y});
	}
	else if(this->way == Way::Right) {
		this->SetPosition({this->GetPosition().x + 1.5,this->GetPosition().y});
	}
}
void Mushroom::Hurt() {
	this->SetDrawable(this->die->GetDrawable());
}
