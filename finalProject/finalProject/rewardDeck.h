#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include "deck.h"
#include "reward.h"

using std::string;
using std::cout;
using std::cin;
using std::array;

#ifndef REWARDDECK_H
#define REWARDDECK_H
class RewardDeck : public Deck<Reward> {
public:
	friend class Reward;
	//make deck method
	static RewardDeck& make_RewardDeck();
	//redefine deck methods
	static array<Reward*, 7> deck;
	static RewardDeck rewardDeck;
	static int size;
	void shuffle();
	Reward* getNext() const;
	bool isEmpty() const;
	~RewardDeck();
private:
	//ctor
	RewardDeck()=default;
	//variables
	
	//dtor

};
#endif