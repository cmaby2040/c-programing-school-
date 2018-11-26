#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include "Card.h"
#include "Deck.h"

using namespace std;

#ifndef CARDDECK_H
#define	CARDDECK_H

class CardDeck : public Deck<Card> {
public:
	friend class Card;
	//static array deck
	static array<Card*, 25> deck;
	//size
	static int size;

	//static cardDeck
	static CardDeck cardDeck;
	//only public method: make_CardDeck method
	static CardDeck& make_CardDeck();
	//deck methods
	void shuffle();
	Card* getNext()const;
	bool isEmpty()const;

private:
	//ctor
	CardDeck();
	//dtor
	~CardDeck();
};
#endif