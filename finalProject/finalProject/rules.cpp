#include "rules.h"

bool Rules::isValid(const Game & _game)
{
	auto prev = _game.getPreviousCard();
	auto current = _game.getCurrentCard();
	//check to see if a match
	if (prev->operator Card::FaceAnimal() == current->operator Card::FaceAnimal()
		|| prev->operator Card::FaceBackground() == current->operator Card::FaceBackground()) {
		return true;
	}
	return false;
}

bool Rules::gameOver(const Game & _game)
{
	//check if round 7
	if (_game.getRound() == 6) {
		return true;
	}
	return false;
}

bool Rules::roundOver(const Game & _game)
{
	int count = 0;

	for (int i = 0; i < _game.numPlayers; i++) {
		if (_game.players[i].isActive()) count++;
	}
	if (count == 1) return true;

	return false;
}


const Player & Rules::getNextPlayer(const Game &)
{

	return Player();
}