#pragma once
#include "game.h"

class Rules {
private:
	Player::Side side;
public:
	Rules();
	bool isValid(const Game& _game);
	bool gameOver(const Game& _game);
	bool roundOver(const Game& _game);
	const Player& getNextPlayer(const Game& _game);
};