#pragma once
#include <iostream>
#include <string>
using std::string;
class Player {

public:
	string getName();
	void setActive(bool);
	bool isActive();
	int getNRubies();
	void addReward(const Reward&); 
	void setDisplayMode(bool endOfGame);
	Side Player::getSide();
	void Player::getSide(Side);
};