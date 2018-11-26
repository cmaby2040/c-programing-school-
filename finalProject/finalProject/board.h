#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include "cardDeck.h"

using namespace std;

class Board {
public:
	
	//enumerators
	enum Letter {
		A, B, C, D, E
	};
	enum Number {
		_1, _2, _3, _4, _5
	};
	//deck for board
	CardDeck* deckBoard;
	//array holds status
	array <string, 19> board;
	//holds card status if up==true, down==false
	array <bool, 25> cardIsUp;

	//METHODS
	//reveals if face up
	//throws exception of type OutOfRange if invalid combo
	bool isFaceUp(const Letter& _letter, const Number& _number)const;
	//turns card up, if already up return false, else true
	//throws exception OutOfRange if invalid combo
	bool turnFaceUp(const Letter& _letter, const Number& _number)const;
	//gets card by reference
	Card* getCard(const Letter& _letter, const Number& _number) const;
	//sets card
	void setCard(const Letter& _letter, const Number& _number) const;
	//turns cards face down
	void reset();
	//output print
	friend ostream& operator<<(ostream& _oStream, const Board& _board);
	//ctor 
	//throws exception of type NoMoreCards if no more cards availbale
	Board();
	//dtor
	~Board();

};