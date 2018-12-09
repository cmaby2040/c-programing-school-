#include "game.h"
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <exception>
#include "board.h"
#include "player.h"
#include "rewardDeck.h"


int Game::round=0;
int Game::numPlayers=0;
CardDeck Game::_c = CardDeck::make_CardDeck();
CardDeck* Game::c = &_c;
RewardDeck Game::_r = RewardDeck::make_RewardDeck();
RewardDeck* Game::r = &_r;
Board Game::gameBoard = Board(c);
std::array<Player *, 4> Game::players;
//starts the game, sets the board
Board Game::getGameBoard() {
	return gameBoard;
}

Game::Game()//no longer shuffle
{
	Game::_c = CardDeck::make_CardDeck();
	_c.shuffle();
	Game::c = &_c;
	Game::gameBoard = Board(c);
	Game::_r = CardDeck::make_CardDeck();
	_r.shuffle();
	Game::r = &_r;
	Game::gameBoard = Board(c);
	Game::round = 0;
	Game::numPlayers = 0;
	const Card * prevCard = nullptr;
	const Card * currentCard = nullptr;
}
RewardDeck& Game::getRewardDeck() {//fix the reward stuff
	return _r;
}
//returns which round
int Game::getRound() const
{
	return round;
}
//increments round and resets game state
void Game::nextRound()
{
	//if last turn game is over
	if (round == 6) {
		cout << "Game is over" << endl;
		return;
	}
	//increment
	round++;
	//reset
	gameBoard.reset();
	//print
	cout << endl << gameBoard <<endl << endl;
}

void Game::addPlayer(const Player & _player)
{
	//get the player enum
	int i=static_cast<int>(_player.getSide());
	//if no player at spot
	if (players[i] == nullptr) {
		//set player
		players[i] = new Player(_player);
	}
	//set that guy to true
	players[i]->setActive(true);
	//increment numplayers
	numPlayers++;
}

Player & Game::getPlayer(Player::Side _side) const
{
	int i = static_cast<int>(_side);
	return *(players[i]);
}

const Card * Game::getPreviousCard() const
{
	return prevCard;
}

 const Card * Game::getCurrentCard() const
{
	return currentCard;
}

 void Game::setCurrentCard(const Card * _card)
 {	
	 this->prevCard = currentCard;
	 //cout << &(*prevCard) << " " << &(*currentCard) << endl;
	//cout << " face animal "<<  prevCard->operator Card::FaceAnimal << " " << currentCard->operator Card::FaceAnimal << endl;
	//cout << " face background" << prev
	 this->currentCard = _card;
	 //cout << &(*prevCard) << " " << &(*currentCard) << endl;
	// if (prevCard != nullptr && currentCard != nullptr) {
	//	 int i1 = static_cast<int>(prevCard->operator Card::FaceAnimal());
	//	 int i2 = static_cast<int>(currentCard->operator Card::FaceAnimal());
	//	 int i3 = static_cast<int>(prevCard->operator Card::FaceBackground());
	//	 int i4 = static_cast<int>(currentCard->operator Card::FaceBackground());
	// }
	 //cout << _card
 }
	/*
	int l = 0;// board letter value
	int n = 0;//board number value

	Card::FaceAnimal animal = _card->operator Card::FaceAnimal();
	cout << " animal card value" << static_cast<int>(animal) << endl;
	Card::FaceBackground background = _card->operator Card::FaceBackground();
	cout << " background card value" << static_cast<int>(background) << endl;
	Card::FaceAnimal tempAnimal = static_cast<Card::FaceAnimal>(0);
	cout << " tempanimal value" << static_cast<int>(tempAnimal) << endl;
	Card::FaceBackground tempBackground = static_cast<Card::FaceBackground>(0);
	cout << " tempbackground card value" << static_cast<int>(tempBackground)<< endl;

	for (int i = 0; i < 5; i++) {//this is to find the 
		tempAnimal = static_cast<Card::FaceAnimal>(i);
		for (int j = 0; j < 5; j++) {
			tempBackground = static_cast<Card::FaceBackground>(j);
			n = j;
			cout << "board number Value " << n << endl;
			if (animal == tempAnimal && background == tempBackground) break;
			cout << "animal == tempAnimal && background == tempBackground" << endl;
			}
			l = i;
			cout << " board letter value" << l << endl;
			if (animal == tempAnimal && background == tempBackground) break;
	}


		Board::Letter _l = static_cast<Board::Letter> (l);
		Board::Number _n = static_cast<Board::Number> (n);
		if (Game::gameBoard.isFaceUp(_l, _n)) {
			Game::gameBoard.turnFaceDown(_l, _n);
		}
		else {
		Game::gameBoard.turnFaceUp(_l, _n);
		//set prev to previous current
		prevCard = currentCard;
		//set current to reference of card
		currentCard = _card;
	}
	*/
Card * Game::getCard(const Board::Letter & _letter, const Board::Number & _number) const
{
	return gameBoard.getCard(_letter, _number);
}

void Game::setCard(const Board::Letter & _letter, const Board::Number & _number, Card * _cardPtr)
{
	gameBoard.setCard(_letter, _number, _cardPtr);
}

Game::~Game()
{
}

ostream & operator<<(ostream & _oStream, const Game & _game)
{
	_oStream << "                      " << " PLAYER MAP " << endl << endl;
	if (_game.players[0] != nullptr) { _oStream << "                      " << *_game.players[0] << endl << endl << endl << endl; }
	if (_game.players[2] != nullptr) { 
		_oStream << *_game.players[2] << "        " << "BOARD           "; 
	}
	else { _oStream << "                          " << "BOARD           "; }
	if (_game.players[3] != nullptr) {
		_oStream << *_game.players[3] << endl << endl << endl << endl;
	}
	else { _oStream << endl << endl << endl << endl; }
	if (_game.players[1] != nullptr) _oStream << "                      " << *_game.players[1] << endl << endl << endl << endl;

	_oStream << _game.gameBoard << endl;
	

	return _oStream;
}

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


	//int firstPerson = 0;
	bool doneLoop = false;
	for (int i = 0; i < 10; ++i) {
		string coords;
		cout << "type the coordinates of the card you want to pick" << endl;
		cin >> coords;
		Board::Letter letter;
		Board::Number number;
		//try catch loop for the coordinates currentilly can tell if both are wrong in the loop
		//letter
		if (coords[0] == 'a' || coords[0] == 'A') {
			letter = Board::Letter::A;
		}
		else if (coords[0] == 'b' || coords[0] == 'B') {
			letter = Board::Letter::B;
		}
		else if (coords[0] == 'c' || coords[0] == 'C') {
			letter = Board::Letter::C;
		}
		else if (coords[0] == 'd' || coords[0] == 'D') {
			letter = Board::Letter::D;
		}
		else if (coords[0] == 'e' || coords[0] == 'E') {
			letter = Board::Letter::E;
		}
		//number
		if (coords[1] == '1') {
			number = Board::Number::_1;
		}
		else if (coords[1] == '2') {
			number = Board::Number::_2;
		}
		else if (coords[1] == '3') {
			number = Board::Number::_3;
		}
		else if (coords[1] == '4') {
			number = Board::Number::_4;

		}
		else if (coords[1] == '5') {
			number = Board::Number::_5;
		}
			
		cout << letter << " " << number << endl;
		g1.getGameBoard().turnFaceUp(letter, number);
		Card* c = g1.getCard(letter, number);
		g1.setCurrentCard(c);
		cout << g1;
	}
}
//*/


