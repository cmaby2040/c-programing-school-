#include "board.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include "cardDeck.h"
#include <exception>

using namespace std;
/*
int main() {
	CardDeck _c = CardDeck::make_CardDeck();
	_c.shuffle();
	CardDeck * c = &_c;
	Board _board = Board(c);
	Board::Letter letter = Board::Letter::B;
	Board::Number number = Board::Number::_5;
	cout << "------------operator << test-----------" << endl;
	cout << _board << endl ;
	cout << "------------turnFaceup test-----------" << endl;
	_board.turnFaceUp(letter, number);
	cout << _board << endl;
	cout << "------------turnFaceDown test-----------" << endl;
	_board.turnFaceDown(letter, number);
	cout << _board;
	cout << "------------is face up test-----------" << endl;
	_board.turnFaceUp(letter, number);
	cout << "At poition B5 the card is face up: " << _board.isFaceUp(letter, number)<< endl;
	cout << "At poition E3 the card is face up:  " << _board.isFaceUp(Board::Letter::E, Board::Number::_3) << endl;
	cout << "------------reset Test-----------" << endl;
	_board.reset();
	cout << _board << endl;
	cout << "------------getCard test at b5-----------" << endl;
	Card* c1= _board.getCard(letter, number);
	cout << *c1;
		_board.reset();
	cout << "------------setCard test at b5 form e3-----------" << endl;
	Card* c2 = _board.getCard(Board::Letter::E, Board::Number::_3);
	_board.setCard(letter, number, c2);
	Card* c3 = _board.getCard(letter, number);
	_board.turnFaceUp(Board::Letter::E, Board::Number::_3);
	cout << *c3 << endl;
	cout << _board;
	return 0; 

}
//*/