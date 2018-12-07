#include "board.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include "cardDeck.h"
#include <exception>

using namespace std; 

//Define NoMoreCards exception
struct NoMoreCards : public exception {
	const char * what() const throw () {
		return "No more cards";
	}
};

//variables
CardDeck* Board::deckBoard;
array <string, 19> Board::board;
array <bool, 25> Board::cardIsUp;

//checks if card is face up, throws exception if illegal combo
//returns true if face up, false otherwise
bool Board::isFaceUp(const Letter & _letter, const Number & _number) const
{
	//which card
	int n = 5 * _letter + _number;
	try {
		if ((_letter > 4 || _letter < 0) && (_number > 4 || _number < 0)) {
			throw "OutOfRange";
		}
		//return whether card is true or not
		return cardIsUp[n];
	}
	catch (out_of_range &e) {
		cout << "Out of range" << e.what() << endl;
	}
	//make sure each block is covered (just to cover each block, doesn't do anything)
	return true;
}

bool Board::turnFaceUp(const Letter & _letter, const Number & _number) const
{	
	//which card
	int n = 5 * _letter + _number;
	try{
		if ((_letter > 4 || _letter < 0) && (_number > 4 || _number < 0)) {
			throw "OutOfRange";
		}	
		if (cardIsUp[n]) {
			return false;
		}
		//if card is not up then set it to true since gonna be up
		cardIsUp[n] = true;
	}
	catch (out_of_range &e) {
		cout << "Out of range" << e.what() << endl;
	}	
	//update the string
	int countRow = 0;
	int countCol = 0;
	//iterate to the correct row
	for (int i = 0; i < _letter; i++) {
		countRow += 4;
	}
	//iterate to the correct column
	for (int j = 0; j < _number; j++) {
		countCol += 4;
	}

	//tempStrings for updated values
	string tempString1, tempString2, tempString3;
	//if before the gap then start from 1
	if (n < 13) {
		tempString1 = deckBoard->cDeck[5 * _letter + _number + 1]->operator()(0);
		tempString2 = deckBoard->cDeck[5 * _letter + _number + 1]->operator()(1);
		tempString3 = deckBoard->cDeck[5 * _letter + _number + 1]->operator()(2);
	}
	//iterate down if after gap (no card in middle so not used)
	else {
		tempString1 = deckBoard->cDeck[5 * _letter + _number ]->operator()(0);
		tempString2 = deckBoard->cDeck[5 * _letter + _number ]->operator()(1);
		tempString3 = deckBoard->cDeck[5 * _letter + _number ]->operator()(2);
	}

	//update row 1
	for (int i = 0; i < 3; i++) {
		board[countRow][countCol + i] = tempString1[i];
	}
	//update row 2
	for (int i = 0; i < 3; i++) {
		board[countRow + 1][countCol + i] = tempString2[i];
	}
	//update row 3
	for (int i = 0; i < 3; i++) {
		board[countRow + 2][countCol + i] = tempString3[i];
	}	return true;
}

bool Board::turnFaceDown(const Letter & _letter, const Number & _number) const
{
	//set n to correct card
	int n = 5 * _letter + _number;
	//if past gap iterate down to take account of that
	if (n > 12) n--;
	try {
		//check range
		if ((_letter > 4 || _letter < 0) && (_number > 4 || _number < 0)) {
			throw "OutOfRange";
		}
		//if already down just return false
		if (!cardIsUp[n]) {
			return false;
		}
		//set cardIsUp to false for that card
		cardIsUp[n] = false;
	}
	catch (out_of_range &e) {
		cout << "Out of range" << e.what() << endl;
	}
	//steps to update the string
	//iterative variables
	int countRow = 0;
	int countCol = 0;
	//iterate to the correct row
	for (int i = 0; i < _letter; i++) {
		countRow += 4;
	}
	//iterate to the correct column
	for (int j = 0; j < _number; j++) {
		countCol += 4;
	}
	
	//update string
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[countRow+i][countCol + j] = 'z';
		}
	}
	return true;
}

Card * Board::getCard(const Letter & _letter, const Number & _number) const
{
	//set to correct n
	int n = 5 * _letter + _number;
	//iterate down if past gap
	if (n > 12) n--;
	try {
		//check if in bounds
		if ((_letter > 4 || _letter < 0) && (_number > 4 || _number < 0)) {
			throw "OutOfRange";
		}
		//return the desired card
		return deckBoard->cDeck[n];
	}
	catch (out_of_range &e) {
		cout << "Out of range" << e.what() << endl;
	}
	//cant get here no matter what, just put to have all paths return Card*
	return deckBoard->cDeck[n];
}

void Board::setCard(const Letter & _letter, const Number & _number, Card* _card) const
{
	//set to correct n
	int n = 5 * _letter + _number;
	//iterate down 1 if past gap
	if (n > 12) n--;
	try {
		//check bounds
		if ((_letter > 4 || _letter < 0) && (_number > 4 || _number < 0)) {
			throw "OutOfRange";
		}
		//set the card
		deckBoard->cDeck[n] = _card;
		//update the string
		int countRow = 0;
		int countCol = 0;
		//iterate to the correct row
		for (int i = 0; i < _letter; i++) {
			countRow += 4;
		}
		//iterate to the correct column
		for (int j = 0; j < _number; j++) {
			countCol += 4;
		}
		//tempStrings for updated values
		string tempString1 = _card->operator()(0);
		string tempString2 = _card->operator()(1);
		string tempString3 = _card->operator()(2);
		//update row 1
		for (int i = 0; i < 3; i++) {
			board[countRow][countCol+i]=tempString1[i];
		}
		//update row 2
		for (int i = 0; i < 3; i++) {
			board[countRow+1][countCol + i] = tempString2[i];
		}
		//update row 3
		for (int i = 0; i < 3; i++) {
			board[countRow+2][countCol + i] = tempString3[i];
		}
	}
	catch (out_of_range &e) {
		cout << "Out of range" << e.what() << endl;
	}
}

void Board::reset()
{
	//set all cardIsUp to false
	for (int i = 0; i < 25; i++) {
		Board::cardIsUp[i] = false;
	}
	int group = 0;
	//set 19 strings to empty strings
	for (int i = 0; i < 19; i++) {
		Board::board[i] = "";
	}
	//fill cards with zzz
	//                zzz
	//                zzz
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 3; k++) {
				string tempString = "zzz";
				Board::board[group + k] += tempString + " ";
			}
		}
		group += 4;
	}
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 3; k++) {
			string tempString = "zzz";
			Board::board[group + k] += tempString + " ";
		}
	}
	for (int k = 0; k < 3; k++) {
		string tempString = "   ";
		Board::board[group + k] += tempString + " ";
	}
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 3; k++) {
			string tempString = "zzz";
			Board::board[group + k] += tempString + " ";
		}
	}
	group += 4;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 3; k++) {
				string tempString = "zzz";
				Board::board[group + k] += tempString + " ";
			}
		}
		group += 4;
	}
}

Board::Board(CardDeck* _cardDeck) {
	Board::deckBoard = _cardDeck;
	//NoMoreCards exception
	if (_cardDeck->isEmpty()) {
	throw "NoMoreCards";
	}
	try {
		//base value for cardIsUp is false
		for (int i = 0; i < 25; i++) {
			Board::cardIsUp[i] = false;
		}

		int group = 0;
		//set 19 strings
		for (int i = 0; i < 19; i++) {
			Board::board[i] = "";
		}
		//fill cards with zzz
		//                zzz
		//                zzz
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 3; k++) {
					string tempString = "zzz";
					Board::board[group + k] += tempString + " ";
				}
			}
			group += 4;
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				string tempString = "zzz";
				Board::board[group + k] += tempString + " ";
			}
		}
		for (int k = 0; k < 3; k++) {
			string tempString = "   ";
			Board::board[group + k] += tempString + " ";
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				string tempString = "zzz";
				Board::board[group + k] += tempString + " ";
			}
		}
		group += 4;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 3; k++) {
					string tempString = "zzz";
					Board::board[group + k] += tempString + " ";
				}
			}
			group += 4;
		}
	}
	//catch block
	catch (NoMoreCards& e) {
		cout << "No more cards!" << e.what() << endl;
	}
}

Board::~Board()
{
	deckBoard->~CardDeck();
}



ostream & operator<<(ostream & _oStream, const Board & _board)
{
	//for each string in board array print it then go to next line
	string temp;
	for (int i = 0; i < 19; i++) {
		temp = _board.board[i];
		_oStream << temp << endl;
	}
	return _oStream;
}

/* TESTTESTTEST*/
int main() {
	CardDeck _c = CardDeck::make_CardDeck();
	_c.shuffle();
	CardDeck * c = &_c;
	Board _board = Board(c);
	cout << _board << endl << endl;
	_board.turnFaceUp(Board::Letter::B, Board::Number::_5);
	_board.turnFaceUp(Board::Letter::A, Board::Number::_4);
	_board.turnFaceUp(Board::Letter::C, Board::Number::_2);
	_board.turnFaceUp(Board::Letter::D, Board::Number::_3);
	_board.turnFaceUp(Board::Letter::E, Board::Number::_1);
	_board.turnFaceUp(Board::Letter::A, Board::Number::_5);
	cout << _board;
	return 0;
}
