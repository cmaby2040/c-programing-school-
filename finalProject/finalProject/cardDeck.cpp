#include "cardDeck.h"
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

//static array deck
array<Card*, 26> CardDeck::cDeck;
//size
int CardDeck::cSize = 25;
int CardDeck::size = 1;
//static cardDeck
CardDeck CardDeck::deckCard;

CardDeck & CardDeck::make_CardDeck()
{
	int count=1;
	//5 animals
	for (int i = 0; i <5; i++) {
		Card::FaceAnimal _animal = static_cast<Card::FaceAnimal>(i);
		//5 colors
		for (int j = 0; j <5; j++) {
			if (count > 25) break;
			Card::FaceBackground _color = static_cast<Card::FaceBackground>(j);
			//set Card* to the new Card
			deckCard.cDeck[count] = new Card(_animal, _color);
			count++;			
		}
	}
	/*// TESTTESTTEST
	for (int i = 0; i < 25; ++i) {
		//deckCard.cDeck[25] = new Card(Card::FaceAnimal::octopus, Card::FaceBackground::blue);
		string strTemp = deckCard.cDeck[i]->operator()(0);
		string strTemp2 = deckCard.cDeck[i]->operator()(1);
		string strTemp3 = deckCard.cDeck[i]->operator()(2);
		cout << "******" << endl << strTemp << endl << strTemp2 << endl << strTemp3 << endl << endl;
	}
	//*/
	return deckCard;
}

void CardDeck::shuffle()
{
	std::random_shuffle(&cDeck[1], &cDeck[25]);
	
	//deck is now shuffled
}

Card * CardDeck::getNext() const
{
	//if not empty
	if (size == 24) {
		size = 1;
	}
	else {
		size++;
	}

	return cDeck[size];
}

bool CardDeck::isEmpty() const
{
	if (cSize <2) return true;
	return false;

}

CardDeck::~CardDeck()
{
	for (int i = 0; i < 25; i++) {
		delete[] cDeck[i];
	}
}
/*
int main() {
	cout << "Card Deck test" << endl;
	cout << "initilization of the deck" << endl;
	CardDeck rew = CardDeck::make_CardDeck();
	cout << "------is empty test---------" << endl;
	cout << rew.isEmpty() << endl;
	cout << "------getNext test---------" << endl;
	for (int i = 0; i < 30; i++) {
		cout << *(rew.getNext());
		cout << "card: " << i+1 << endl;
	}
	return 0;

	CardDeck rew2 = CardDeck::make_CardDeck();
	cout << "------shuffle test---------" << endl;
	rew2.shuffle();
	for (int i = 0; i < 30; i++) {
		cout << *(rew.getNext());
		cout << "card: " << i + 1 << endl;
	}
	return 0;

}
//*/
