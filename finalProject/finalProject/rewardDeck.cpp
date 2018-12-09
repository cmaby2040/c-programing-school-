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

array<Reward*,7> RewardDeck::deck;
RewardDeck RewardDeck::rewardDeck;
int RewardDeck::size = 0;


void RewardDeck::shuffle()
{
	std::random_shuffle(&deck[0], &deck[6]);

	//deck is now shuffled
}

RewardDeck & RewardDeck::make_RewardDeck()
{
	//set rewards for each one
	Reward::Rubies ruby1 = Reward::Rubies(1);
	Reward::Rubies ruby2 = Reward::Rubies(2);
	Reward::Rubies ruby3 = Reward::Rubies(3);
	Reward::Rubies ruby4 = Reward::Rubies(4);
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
Reward * RewardDeck::getNext() const//with the way that make_RewardDeck is created there is no way for the deck to be empty of not full
{
	//Reward* temp;
	//if not empty
		//int i = 0;
		if (size == 6) {
			size = 0;
		}
		else {
			size++;
		}

		return deck[size];
}

bool RewardDeck::isEmpty() const
{
	bool state = true;
	for (int i = 0; i < 7; i++) {
		if (deck[i] != nullptr) {
			 return false;
		}
	}
	return state;
}

RewardDeck::~RewardDeck()
{
	for (int i = 0; i < 7; i++) {
		delete[] deck[i];
	}
}
/*
int main() {
	//RewardDeck r();
	cout << "Reward Deck test" << endl;
	cout << "initilization of the deck" << endl;
	RewardDeck rew = RewardDeck::make_RewardDeck();
	cout << "------is empty test---------" << endl;
	cout << rew.isEmpty() << endl;
	cout << "------getNext test---------" << endl;
	for (int i = 0; i < 10; i++) {
		cout << *(rew.getNext());
	}
	RewardDeck rew2 = RewardDeck::make_RewardDeck();
	cout << "------shuffle test---------" << endl;
	rew2.shuffle();
	for (int i = 0; i < 10; i++) {
		cout << *(rew.getNext());
	}
	return 0;
}
//*/

