#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include "card.h"
#include "deck.h"

using std::string;
using std::cout;
using std::cin;
using std::array;

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
	//dtor
	~CardDeck();
private:
	//ctor
	CardDeck()=default;
};
#endif