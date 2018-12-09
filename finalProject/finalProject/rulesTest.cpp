#include "rules.h"
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
	cout << "------------------- isValid Test--------------------" << endl;
	Rules r = Rules();
	//r.gameOver(game);
	cout <<"first valid B2 E5"<< " " <<   r.isValid(game) << endl;
	c = game.getGameBoard().getCard(Board::Letter::C, Board::Number::_1);
	game.setCurrentCard(c);
	c2 = game.getGameBoard().getCard(Board::Letter::C, Board::Number::_5);
	game.setCurrentCard(c2);
	cout << "second valid C1 C5" <<" " << r.isValid(game) << endl;
	c = game.getGameBoard().getCard(Board::Letter::B, Board::Number::_1);
	game.setCurrentCard(c);
	c2 = game.getGameBoard().getCard(Board::Letter::C, Board::Number::_5);
	game.setCurrentCard(c2);
	cout << "third valid B1 C5" << " " << r.isValid(game) << endl;
	cout << "------------------- GameOver Test--------------------" << endl;
	for (int i = 0; i < 7; ++i) {
		cout << "round: " << game.getRound() << endl;
		game.nextRound();
		cout << "gameover" << r.gameOver(game) << endl;
	}
	cout << "------------------- RoundOver Test--------------------" << endl;
	cout << "before all player are false round over: " << r.roundOver(game) << endl;
	Game game1 = Game();
	game1.addPlayer(player);//this auto sets the players to active
	game1.addPlayer(player2);
	game1.addPlayer(player3);
	game1.addPlayer(player4);
	for (int i = 0; i < game.numPlayers-1; ++i) {
		auto val = static_cast<Player::Side>(i);
		game1.getPlayer(val).setActive(false);
	}
	cout << "after all player are false round over: " << r.roundOver(game) << endl;
	for (int i = 0; i < game.numPlayers; ++i) {
		auto val = static_cast<Player::Side>(i);
		game1.getPlayer(val).setActive(true);
	}

	cout << "-------------------nextPlayer Test--------------------" << endl;
	cout << "before using the getNextPlayer" << endl;
	for (int i = 0; i < game.numPlayers; ++i) {
		auto val = static_cast<Player::Side>(i);
		cout<< "player: " << i <<" " << game1.getPlayer(val) <<endl;
	}
	cout << "Using the getNextPlayer" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << r.getNextPlayer(game) << endl;;
	}
}
//*/