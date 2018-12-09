#include "player.h"
#include "reward.h"
#include "rules.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
Player::Player(string name, bool activ, int rub, Side playerSide) : name{ name }, active{ activ }, rubies{ rub }, plyrSde{ playerSide }{gameOver = false; }// gameOver{ gameOver }{}

Player::Player(const Player& p): name{ p.name }, active{ p.active }, rubies{ p.rubies }, plyrSde{ p.plyrSde }, gameOver{ gameOver } {}

Player::Player() : name{ "noName" }, active{ true }, rubies{ 0 }{}

string Player::getName() const {
	return name;
}
void Player::setActive(bool act) {
	active = act;
}
bool Player::isActive() const {
	return active;
}
int Player::getNrubies() const {
	return rubies;
}
void Player::addReward(const Reward& r) {
	rubies += static_cast<int>(r);
}
Player::Side Player::getSide() const {//this print out needs work
	return plyrSde;
}
void Player::setSide(Side side) {
	plyrSde = side;
}
//static bool getGameOver(const Player& f) {
	//return f.gameOver;
//}
std::ostream& operator<<(std::ostream& out, const Player& f) {// need to fix this class for the game values
	string s;
	int i = static_cast<int>(f.getSide());
	switch (i) {
		//case Side::defaultplayer: s="defaultplayer"; break;
	case 0: s = "top"; break;
	case 1: s = "bottom"; break;
	case 2: s = "left"; break;
	case 3: s = "right"; break;
	}
	//if (f.getGameOver())
	if (f.isActive() == 1) {
		out << f.getName() << ": " << s << "(active)" ;
	}
	else {

		out << f.getName() << ": " << f.getNrubies() << " rubies";
	}
	return out;
}


Player& Player::operator=(const Player& p) {
	name = p.getName();
	rubies = p.getNrubies();
	plyrSde = p.getSide();
	active = p.isActive();
	return *this;
}
/*
	int main(){
		Player p1();
		Player p2("christopher" , false, 3, Player::Side::top);
		Player p3("christopher", true, 3, Player::Side::left);
		cout << p2.getName() << " " << p2.getNrubies() << " " << p2.getSide() << " " << p2.isActive()<< endl;
		cout << p2 << p3;
		p2.setSide(Player::Side::bottom);
		cout << p2;
		p2.setActive(1);//changes the output type to name: side(active)
		cout << p2;
		return 0;


	}
	
	*/