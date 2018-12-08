#include "rules.h"

using namespace std;

Rules::Rules() {
	side = Player::Side::top;
}

bool Rules::isValid(const Game & _game)
{
	auto prev = _game.getPreviousCard();
	auto current = _game.getCurrentCard();
	//check to see if a match
	if (prev == nullptr || current == nullptr) {
		cout << "isValid test false" << endl;
		return false;
	}
	if (prev->operator Card::FaceAnimal() == current->operator Card::FaceAnimal()
		|| prev->operator Card::FaceBackground() == current->operator Card::FaceBackground()) {
		cout << "test isvalid true" << endl;
		return true;
	}
	cout << "test isvalid false" << endl;
	return false;
}

bool Rules::gameOver(const Game & _game)
{
	//check if round 7
	if (_game.getRound() == 6) {
		cout << "test gameover true" << endl;
		return true;
	}
	cout << "test gameover false" << endl;
	return false;
}

bool Rules::roundOver(const Game & _game)
{
	int count = 0;

	for (int i = 0; i < _game.numPlayers; i++) {
		if (_game.players[i]->isActive()) count++;
	}
	if (count == 1) {
		cout << "test roundOver true" << endl;
		return true;
	}
	cout << "test roundover false" << endl;
	return false;
}


const Player & Rules::getNextPlayer(const Game & _game)
{
	
	bool empty = true;
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (_game.players[i] != nullptr) {
			count++;
		}
	}
	if (count < 2) {
		cout << "no next players" <<endl;
		Player fail = Player("fail", false, 0, Player::Side::top);
		return fail;	}
	else {

		//get the int of the side of the current player
		int i = static_cast<int>(side);
		if (i == _game.numPlayers - 1) {
			i = 0;
		}
		else {
			i++;
		}
		side = static_cast<Player::Side>(i);
		while (!(_game.getPlayer(side).isActive())) {
			if (i = _game.numPlayers - 1) {
				i = 0;
			}
			else i++;
			side = static_cast<Player::Side>(i);
		}
		return _game.getPlayer(side);
	}
}

int main() {
	Player::Side side = Player::Side::top;
	string name = "bruh";
	Player::Side side2 = Player::Side::bottom;
	string name2 = "kobe";
	Player::Side side3 = Player::Side::left;
	string name3 = "Lebron";
	Player::Side side4 = Player::Side::right;
	string name4 = "shaq";
	const Player player = Player(name, true, 0, side);
	const Player player2 = Player(name2, true, 0, side2);
	const Player player3 = Player(name3, true, 0, side3);
	const Player player4 = Player(name4, true, 0, side4);

	Game game = Game();
	game.addPlayer(player);
	game.addPlayer(player2);
	game.addPlayer(player3);
	game.addPlayer(player4);
	game.getPlayer(side);
	Rules r = Rules();
	r.gameOver(game);
	r.isValid(game);
	r.roundOver(game);
	r.getNextPlayer(game);
	cout << game;
}
