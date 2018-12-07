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
array<Card*, 26> CardDeck::cDeck ;
//size
int CardDeck::cSize = 25;
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
	/* TESTTESTTEST
	deckCard.cDeck[25] = new Card(Card::FaceAnimal::Gorilla, Card::FaceBackground::blue);
	string strTemp = deckCard.cDeck[count]->operator()(0);
	string strTemp2 = deckCard.cDeck[count]->operator()(1);
	string strTemp3 = deckCard.cDeck[count]->operator()(2);
	cout << "******" << endl << strTemp << endl << strTemp2 << endl << strTemp3 << endl << endl;
	*/
	return deckCard;
}

// NEED TO CHANGE ************************************************************
void CardDeck::shuffle()
{
	for (int i = 0; i < 25; i++) {
		int r = rand() % 25; // random variable 
		//temp=a, a=b, b=a
		Card* temp = cDeck[i]; cDeck[i] = cDeck[r]; cDeck[r] = temp; 
	}
	//deck is now shuffled
}

Card * CardDeck::getNext() const
{
	//if not empty
	if (!this->isEmpty()) {
		int i = 0;
		//check to see if deck at i==nullptr
		while (cDeck[i] == nullptr) {
			i++;
		}
		Card* temp = cDeck[i];
		//set element to null after getting next
		cDeck[i-1] = nullptr;
		return temp;
		cSize--;
	}
	//print in case no more cards
	cout << "no more cards" << endl;
	return nullptr;
}

bool CardDeck::isEmpty() const
{
	if (cSize == 0) return true;
	return false;

}

CardDeck::~CardDeck()
{
	
}
