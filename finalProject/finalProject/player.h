#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>


 
using std::string;
using std::endl;
using std::cout;
enum class Side{defaultplayer=0, top,bottom,left,right};

inline std::ostream& operator<<(std::ostream& out, Side f) {//output the enum how we want it to output the right stuff
    switch (f) {
        case Side::defaultplayer: out << "defaultplayer"; break;
        case Side::top: out << "top"; break;
        case Side::bottom: out << "bottom"; break;
        case Side::left: out<< "left"; break;
        case Side::right:out << "right"; break;
        default: out << int(f); break;
    }
    return out;
}
class Player{
	
	private:
		string name;
		bool active;
		int rubies;
		Side plyrSde;
	public:
		Player();
		Player(string name, bool activ, int rubies, Side playerside);
		string getName() const;
		void setActive(bool act);
		bool isActive() const;
		int getNrubies() const;
	//	void addReward(const Reward& );
		Side getSide() const;
		void setSide(Side);	
};




#endif
