#pragma once
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <exception>
#include "board.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

using namespace std;


class Game {

private: 
	//variables
	//*************might make private
	static CardDeck _c;
	static CardDeck * c;
	static Board gameBoard;
	static int round;
	const Card * prevCard;
	const Card *currentCard;
public:
	static int numPlayers;
	static array<Player, 4> players;
	//ctor
	Game();
	//return round number
	int getRound() const;
	//set state to next rd
	void nextRound();
	//add player
	void addPlayer(const Player&);
	//get player at enum side
	Player& getPlayer(Player::Side _side) const;
	//get Previous card
	const Card* getPreviousCard() const;
	//get current card
	const Card* getCurrentCard() const;
	//set current card
	void setCurrentCard(const Card* _card);
	//get card
	Card* getCard(const Board::Letter& _letter, const Board::Number& _number) const;
	//set card
	void setCard(const Board::Letter& _letter, const Board::Number& _number, Card* _cardPtr);
	
	//output print
	friend ostream& operator<<(ostream& _oStream, const Game& _game);
	//dtor
	~Game();
};
#endif