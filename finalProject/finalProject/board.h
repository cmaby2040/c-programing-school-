#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include "cardDeck.h"

using namespace std;

#ifndef BOARD_H
#define BOARD_H
class Board {
public:
	
	//enumerators
	enum Letter {
		A=0, 
		B, 
		C, 
		D, 
		E
	};
	enum Number {
		_1=0, 
		_2, 
		_3, 
		_4, 
		_5
	};

	//METHODS
	//reveals if face up
	//throws exception of type OutOfRange if invalid combo
	bool isFaceUp(const Letter& _letter, const Number& _number)const;//good
	//turns card up, if already up return false, else true
	bool turnFaceUp(const Letter& _letter, const Number& _number)const;// good
	//turns card down, false if already down
	//throws exception OutOfRange if invalid combo
	bool turnFaceDown(const Letter& _letter, const Number& _number)const;//good
	//gets card by reference
	Card* getCard(const Letter& _letter, const Number& _number) const;
	//sets card
	void setCard(const Letter& _letter, const Number& _number, Card* _card) const;// what do these do?
	//turns cards face down
	void reset();//good
	//output print
	friend ostream& operator<<(ostream& _oStream, const Board& _board);
	//ctor 
	//throws exception of type NoMoreCards if no more cards availbale
	Board(CardDeck* _cardDeck);
	//dtor
	~Board();
private:
	static array <string, 19> board;
	//deck for board
	static CardDeck* deckBoard;
	//array holds status
	//holds card status if up==true, down==false
	static array <bool, 25> cardIsUp;
};
#endif