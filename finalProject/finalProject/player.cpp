#include "player.h"
#include <string>
#include <iostream>
	using std::string;
	using std::cout;
	using std::endl;
	Player::Player(string name, bool activ, int rub, Side playerSide): name{name},active{activ},rubies{rub}, plyrSde{playerSide}{}
	
	Player::Player(): name{"noName"}, active{true}, rubies{0}, plyrSde{Side::defaultplayer}{}
	
	string Player::getName() const {
		return name;
	}
	void Player::setActive(bool act){
		active=act;
	}
	bool Player::isActive() const{
		return active;
	}
	int Player::getNrubies() const{
		return rubies;
	}
	//void Player::addReward(const Reward& r){
		// rubies= some value
//  }
	Side Player::getSide() const{//this print out needs work
		return plyrSde;
	}
	void Player::setSide(Side side){
		plyrSde=side;
	}
	inline std::ostream& operator<<(std::ostream& out, const Player& f){//in this finction impotant to toggle activeness at end of game
	if (f.isActive()==1){
		out << f.getName() << ": " << f.getSide() << "(ative)" << endl; 
	}else{
	
	out << f.getName() << ": " << f.getNrubies() << " rubies" << endl;
	}
	return out;
}

/*
	int main(){
		Player p1();
		Player p2("christopher" , false, 3, Side::defaultplayer);
		Player p3("christopher", true, 3, Side::left);
		cout << p2.getName() << " " << p2.getNrubies() << " " << p2.getSide() << " " << p2.isActive()<< endl;
		cout << p2 << p3;
		p2.setSide(Side::bottom);
		cout << p2;
		p2.setActive(1);//changes the output type to name: side(active)
		cout << p2;
		return 0;
		
	
	}
	*/
	
