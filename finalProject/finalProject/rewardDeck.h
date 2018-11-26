#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include "deck.h"
#include "reward.h"

using namespace std;

#ifndef REWARDDECK_H
#define REWARDDECK_H
class RewardDeck : public Deck<Reward> {
public:
	friend class Reward;
	//variables
	static array<Reward*, 7> rewardDeck;
	static int size;
	//make deck method
	static RewardDeck& make_RewardDeck();
	//redefine deck methods
	void shuffle();
	Reward* getNext() const;
	bool isEmpty() const;

private:
	//ctor
	RewardDeck();
	//dtor
	~RewardDeck();
};
#endif