#include "rewardDeck.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include "Card.h"
#include "Deck.h"
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::array;

array<Reward*, 7> RewardDeck::deck;
RewardDeck RewardDeck::rewardDeck;


void RewardDeck::shuffle()
{
		for (int i = 0; i < 7; i++) {
			int r = rand() % 7; // random variable 
			//temp=a, a=b, b=a
			Reward* temp = this->deck[i]; this->deck[i] = this->deck[r]; this->deck[r] = temp;
		}
		//rewarddeck is now shuffled
}

RewardDeck & RewardDeck::make_RewardDeck()
{
	//set rewards for each one
	Reward::Rubies ruby1 = Reward::Rubies(0);
	Reward::Rubies ruby2 = Reward::Rubies(1);
	Reward::Rubies ruby3 = Reward::Rubies(2);
	Reward::Rubies ruby4 = Reward::Rubies(3);
	//set the correct rewards in the deck
	rewardDeck.deck[0] = new Reward(ruby1);
	rewardDeck.deck[1] = new Reward(ruby1);
	rewardDeck.deck[2] = new Reward(ruby1);
	rewardDeck.deck[3] = new Reward(ruby2);
	rewardDeck.deck[4] = new Reward(ruby2);
	rewardDeck.deck[5] = new Reward(ruby3);
	rewardDeck.deck[6] = new Reward(ruby4);

	return rewardDeck;
}
Reward * RewardDeck::getNext() const
{
	//if not empty
	if (!this->isEmpty()) {
		int i = 0;
		//check to see if deck at i==nullptr
		while (this->deck[i] != nullptr) {
			i++;
		}
		Reward* temp = this->deck[i];
		//set element to null after getting next
		this->deck[i] = nullptr;
		return temp;
	}
	cout << "no more rewards" << endl;
	return nullptr;
}

bool RewardDeck::isEmpty() const
{
	for (int i = 0; i < 7; i++) {
		if (this->deck[i] != nullptr) {
			return false;
		}
	}
		return true;
}

RewardDeck::~RewardDeck()
{
	for (int i = 0; i < 7; i++) {
		delete this->deck[i];
	}
}
