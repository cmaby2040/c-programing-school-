#include "player.h"
#include "rules.h"
#include "game.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
using std::cout;
using std::endl;
using std::string;
using namespace std::this_thread;
using namespace std::chrono; 
int main() {
	Rules rules = Rules();
	int gametype, numberplayers;
	string s, name, subName;
	bool doneLoop = false;
	while (!doneLoop) {
		try {
			cout << " which type of game would you like to play 1)expert 2)regular \n";
			cin >> gametype;
			if ((gametype != 1 || gametype != 2) && (gametype == 1 || gametype != 2) && (gametype != 1 || gametype == 2)) {
				throw - 1;
			}
			doneLoop = true;
		}
		catch (int) {
			cout << "must be an interger value 1 or 2" << endl;

		}
	}
	doneLoop = false;
	while (!doneLoop) {
		try {
			cout << "how many players would you like to play with. Choose between 2-4:" << endl;
			cin >> numberplayers;
			cout << numberplayers << endl;
			if (numberplayers < 2) {
				throw - 1;
			}if (numberplayers > 4) {
				throw - 1;
			}
			doneLoop = true;
		}
		catch (int) {
			cout << "must be an interger value between 2-4" << endl;
		}
	}

	for (int i = 1; i < numberplayers + 1; i++) {
		cout << "type player " << i << " name." << endl;
		cin >> name;
		s += name + ":";// us the space to differentiate names of strings
	}

	Game game = Game();

	for (int i = 0; i < numberplayers; ++i) {//creates each player
		int j;
		//if (i == 0) {//parse string
			j = s.find_first_of(':');
		//}
		//else {
			j = s.find_first_of(':', j);
		//}
		//if (i == 0) {
			subName = s.substr(0, j);
		//}
		//else {
			//subName = s.substr(1, j - 1);
		//}
		s = s.erase(0, j + 1);//get rid of old nam

		Player::Side side; //creating each player object
		if (i == 0) {
			side = Player::Side::top;
		}
		else if (i == 1) {
			side = Player::Side::bottom;
		}
		else if (i == 2) {
			side = Player::Side::left;
		}
		else {
			side = Player::Side::right;
		}
		const Player p1(subName, 0, 0, side);
		cout << p1;
		game.addPlayer(p1); //add player into game
	}
	
	while (!rules.gameOver(game)){
		game.nextRound(); //reset the cards that
		for (int i=0 ; i<numberplayers ; ++i){
			game.players[i]->setActive(true);
		}
		for (int i=0; i<numberplayers; ++i){// order is top,bootom left right
			Board::Letter a = Board::Letter::A;
			Board::Letter b = Board::Letter::B;
			Board::Letter c = Board::Letter::C;
			Board::Letter d = Board::Letter::D;
			Board::Letter e = Board::Letter::E;
			Board::Number one = Board::Number::_1;
			Board::Number two = Board::Number::_2;
			Board::Number three = Board::Number::_3;
			Board::Number four = Board::Number::_4;
			Board::Number five = Board::Number::_5;
			const Card* a2 = game.getCard(a, two);
			const Card* a3 = game.getCard(a, three);
			const Card* a4 = game.getCard(a, four);
			const Card* e2 = game.getCard(e, two);
			const Card* e3 = game.getCard(e, three);
			const Card* e4 = game.getCard(e, four);
			const Card* b1 = game.getCard(b, one);
			const Card* c1 = game.getCard(c, one);
			const Card* d1 = game.getCard(d, one);
			const Card* b5 = game.getCard(b, five);
			const Card* c5 = game.getCard(c, five);
			const Card* d5 = game.getCard(d, five);
			
			array<const Card*, 12> flips = { a2,a3,a4,e2,e3,e4,b1,c1,d1,b5,c5,d5 };
			//flip up
			if (game.numPlayers == 2) {
				for (int i = 0; i < 6; i++) {
					game.setCurrentCard(flips[i]);
				}

				//pause
				sleep_until(system_clock::now() + seconds(3));
				//flip down
				for (int i = 0; i < 6; i++) {
					game.setCurrentCard(flips[i]);
				}
			}
			if (game.numPlayers == 3) {
				for (int i = 0; i < 9; i++) {
					game.setCurrentCard(flips[i]);
				}

				//pause
				sleep_until(system_clock::now() + seconds(5));
				//flip down
				for (int i = 0; i < 9; i++) {
					game.setCurrentCard(flips[i]);
				}
			}
			if (game.numPlayers == 4) {
				for (int i = 0; i < 12; i++) {
					game.setCurrentCard(flips[i]);
				}

				//pause
				sleep_until(system_clock::now() + seconds(3));
				//flip down
				for (int i = 0; i < 12; i++) {
					game.setCurrentCard(flips[i]);
				}
			}
			//flip cards for each player temporarily
			
		}
		while(!rules.roundOver(game)){
			
			//cycle throught the active players flipping and testing cards
		}
	}

}