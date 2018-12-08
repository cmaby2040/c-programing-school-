#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "reward.h"


using std::string;
using std::endl;
using std::cout;
using std::ostream;




class Player {
public:
	enum Side { top = 0, bottom, left, right };

	//enum class Side{defaultplayer=0, top=1,bottom=2,left=3,right=4};// this to enumerate each type of player
		//some other shit here
private:
	string name;
	bool active;
	int rubies;
	Side plyrSde;
public:
	Player();
	Player(string name, bool activ, int rubies, Side playerside);

	Player(const Player&);
	friend ostream & operator<<(ostream&, const Player&);

	//friend std::ostream& operator<<(std::ostream& out, Side& f);
	Player& operator= (const Player&);
	string getName() const;
	void setActive(bool act);
	bool isActive() const;
	int getNrubies() const;
	void addReward(const Reward& r);
	Side getSide() const;
	void setSide(Side side);





};
#endif