#include "rules.h"

using namespace std;

Rules::Rules() :currentSide{ Player::Side::top } {//here we are assuming that the top player always starts the game as there was no indication that 
												  // there is a specific order of players to start
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
	else {

		if (prev == nullptr) {
			cout << "prev is nullptr" << endl;
		}if (current == nullptr) {
			cout << "current is nullptr" << endl;
		}
		//cout << "prev and current faceanimal and then facebackgroud" << endl;
		int i1 = static_cast<int>(prev->operator Card::FaceAnimal());
		int i2 = static_cast<int>(current->operator Card::FaceAnimal());
		int i3 = static_cast<int>(prev->operator Card::FaceBackground());
		int i4 = static_cast<int>(current->operator Card::FaceBackground());
		//cout << "animal: " << "prev: " << i1 << "curr " << i2 << endl;
		//cout << "background " << "prev: " << i3 << "curr " << i4 << endl;
		if (i1 == i2 || i3 == i4) {
			cout << "test isvalid true" << endl;
			return true;
		}
		cout << "test isvalid false" << endl;
	}
	return false;
}

bool Rules::gameOver(const Game & _game)
{
	//check if round 7
	if (_game.getRound() == 6) {
		//cout << "test gameover true" << endl;
		return true;
	}
	//cout << "test gameover false" << endl;
	return false;
}

bool Rules::roundOver(const Game & _game)
{
	int count = 0;

	for (int i = 0; i < _game.numPlayers; i++) {
		if (_game.players[i]->isActive()) count++;
	}
	if (count == 1) {
		//cout << "test roundOver true" << endl;
		return true;
	}
	//cout << "test roundover false" << endl;
	return false;
}


const Player & Rules::getNextPlayer(const Game & _game)//this method is fixed we all good
{
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (_game.players[i] != nullptr) {//check to see the
			count++;
		}
	}
	if (count < 2) {
		cout << "no next players" <<endl;
		//Player fail = Player("fail", false, 0, Player::Side::top);
		//return fail;	
	}
	else {

		int i = static_cast<int>(currentSide);//go to the next element of the array
		if (i == _game.numPlayers-1) {
			i = 0;
		}
		else {
			i++;
		}
		Player::Side side = static_cast<Player::Side>(i);//incremented player value
		if (_game.getPlayer(side).isActive()==true) {//base case where the next player is active.
			this->setCurrentSide(side);
		}else {//case were the next player is not active
			//currentSide = static_cast<Player::Side>(i);
			while (_game.getPlayer(side).isActive() == false) {
				i = static_cast<int>(side);
				if (i == _game.numPlayers-1) {
					i = 0;
				}
				else {
					i++;
				}
				side = static_cast<Player::Side>(i);
			}
			this->setCurrentSide(side);
		}
		

		//cout << _game.getPlayer(currentSide) <<endl;
		
	}
	return _game.getPlayer(currentSide);
}
Player::Side Rules::getCurrentSide() {
	return this->currentSide;
}
void Rules::setCurrentSide(Player::Side p) {
	this->currentSide = p;

}
//*/
/*
int main() {
	Player::Side side = Player::Side::top;
	string name = "bruh";
	Player::Side side2 = Player::Side::bottom;
	string name2 = "kobe";
	Player::Side side3 = Player::Side::left;
	string name3 = "Lebron";
	Player::Side side4 = Player::Side::right;
	string name4 = "shaq";
	const Player player = Player(name, true, 0, side);//top
	const Player player2 = Player(name2, true, 0, side2);//bottom
	const Player player3 = Player(name3, true, 0, side3);//left
	const Player player4 = Player(name4, true, 0, side4);//right

	Game game = Game();
	game.addPlayer(player);//this auto sets the players to active
	game.addPlayer(player2);
	game.addPlayer(player3);
	game.addPlayer(player4);
	game.getPlayer(side);
	game.getGameBoard().turnFaceUp(Board::Letter::A, Board::Number::_1);
	game.getGameBoard().turnFaceUp(Board::Letter::A, Board::Number::_2);
	game.getGameBoard().turnFaceUp(Board::Letter::A, Board::Number::_3);
	game.getGameBoard().turnFaceUp(Board::Letter::A, Board::Number::_4);
	game.getGameBoard().turnFaceUp(Board::Letter::A, Board::Number::_5);
	game.getGameBoard().turnFaceUp(Board::Letter::B, Board::Number::_1);
	game.getGameBoard().turnFaceUp(Board::Letter::B, Board::Number::_2);
	game.getGameBoard().turnFaceUp(Board::Letter::B, Board::Number::_3);
	game.getGameBoard().turnFaceUp(Board::Letter::B, Board::Number::_4);
	game.getGameBoard().turnFaceUp(Board::Letter::B, Board::Number::_5);
	game.getGameBoard().turnFaceUp(Board::Letter::C, Board::Number::_1);
	game.getGameBoard().turnFaceUp(Board::Letter::C, Board::Number::_2);
	//game.getGameBoard().turnFaceUp(Board::Letter::C, Board::Number::_3);
	game.getGameBoard().turnFaceUp(Board::Letter::C, Board::Number::_4);
	game.getGameBoard().turnFaceUp(Board::Letter::C, Board::Number::_5);
	game.getGameBoard().turnFaceUp(Board::Letter::D, Board::Number::_1);
	game.getGameBoard().turnFaceUp(Board::Letter::D, Board::Number::_2);
	game.getGameBoard().turnFaceUp(Board::Letter::D, Board::Number::_3);
	game.getGameBoard().turnFaceUp(Board::Letter::D, Board::Number::_4);
	game.getGameBoard().turnFaceUp(Board::Letter::D, Board::Number::_5);
	game.getGameBoard().turnFaceUp(Board::Letter::E, Board::Number::_1);
	game.getGameBoard().turnFaceUp(Board::Letter::E, Board::Number::_2);
	game.getGameBoard().turnFaceUp(Board::Letter::E, Board::Number::_3);
	game.getGameBoard().turnFaceUp(Board::Letter::E, Board::Number::_4);
	game.getGameBoard().turnFaceUp(Board::Letter::E, Board::Number::_5);
	cout << game;
	Card* c = game.getGameBoard().getCard(Board::Letter::B, Board::Number::_2);
	game.setCurrentCard(c);
	Card* c2 = game.getGameBoard().getCard(Board::Letter::E, Board::Number::_5);
	game.setCurrentCard(c2);
	//game.setCurrentCard(c);
	Rules r = Rules();
	//r.gameOver(game);
	r.isValid(game);
	//r.roundOver(game);
	//game.getPlayer(Player::Side::bottom).setActive(false);
	//game.getPlayer(Player::Side::right).setActive(false);
	//r.getNextPlayer(game);
	//r.getNextPlayer(game);
	//r.getNextPlayer(game);
	//cout << game.getPlayer(Player::Side::left) << endl;
	//game.getPlayer(Player::Side::bottom).setActive(false);
	//cout << game.getPlayer(Player::Side::left) << endl;
	//r.getNextPlayer(game);
	//r.getNextPlayer(game);
	//cout << game;
}
//*/

