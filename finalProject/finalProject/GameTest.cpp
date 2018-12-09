#include "game.h"
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <exception>
#include "board.h"
#include "player.h"
#include "rewardDeck.h"
/*
int main() {
	Game g1 = Game();

	Player p1("chris", 1, 0, Player::Side::top);
	Player p2("chris", 1, 0, Player::Side::bottom);
	Player p3("chris", 1, 0, Player::Side::left);
	//cout << p1;
	g1.addPlayer(p1);
	g1.addPlayer(p2);
	g1.addPlayer(p3);
	cout << g1;
	cout << "-------------test addReward--------------" << endl;
	Reward* r1 = g1.getRewardDeck()->getNext();
	g1.getPlayer(Player::Side::top).addReward(*r1);
	cout << *r1;
	g1.getPlayer(Player::Side::top).setActive(false);
	cout << g1.getPlayer(Player::Side::top) << endl;
	cout << "-------------test nextRound and getRound--------------" << endl;
	cout <<"initial round: " << g1.getRound() << endl;
	g1.nextRound();
	cout <<"after round: " << g1.getRound() << endl;
	cout << "-------------test getPlayer--------------" << endl;
	cout << "getting the first player" << endl;
	cout << g1.getPlayer(Player::Side::top) << endl;
	cout << "-------------test setCurrentCard at E3 prev B5 current--------------" << endl;
	Card* c1 = g1.getCard(Board::Letter::E, Board::Number::_3);
	g1.setCurrentCard(c1);
	cout << "first current: \n" << *(g1.getCurrentCard()) << endl;
	Card* c2 = g1.getCard(Board::Letter::B, Board::Number::_5);
	g1.setCurrentCard(c2);
	cout << "previous card \n" << *(g1.getPreviousCard()) << endl;
	cout << "second current card \n" << *(g1.getCurrentCard()) << endl;
}
//*/