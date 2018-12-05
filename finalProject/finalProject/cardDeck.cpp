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
static array<Card*, 25> deck;
//size
static int size;
//static cardDeck
static CardDeck cardDeck;

CardDeck & CardDeck::make_CardDeck()
{
	cardDeck = CardDeck();
	int count=0;
	for (int i = Card::FaceAnimal::Penguin; i != Card::FaceAnimal::Gorilla; i++) {
		Card::FaceAnimal _animal = static_cast<Card::FaceAnimal>(i);
		for (int j = Card::FaceBackground::red; j != Card::FaceBackground::blue; j++) {
			Card::FaceBackground _color = static_cast<Card::FaceBackground>(j);
			cardDeck.deck[count] = new Card(_animal, _color);
			count++;
		}
	}
	return cardDeck;
}


void CardDeck::shuffle()
{
	for (int i = 0; i < 25; i++) {
		int r = rand() % 25; // random variable 
		//temp=a, a=b, b=a
		Card* temp = deck[i]; deck[i] = deck[r]; deck[r] = temp; 
	}
	//deck is now shuffled
}

Card * CardDeck::getNext() const
{
	//if not empty
	if (!this->isEmpty()) {
		int i = 0;
		//check to see if deck at i==nullptr
		while (deck[i] != nullptr) {
			i++;
		}
		Card* temp = deck[i];
		//set element to null after getting next
		deck[i] = nullptr;
		return temp;
	}
	cout << "no more cards" << endl;
	return nullptr;
}

bool CardDeck::isEmpty() const
{
	for (int i = 0; i < 25; i++) {
		if (deck[i] != nullptr) {
			return false;
		}
	}
	return true;

}

CardDeck::~CardDeck()
{
	for (int i = 0; i < 25; i++) {
		delete cardDeck.deck[i];
	}
}
