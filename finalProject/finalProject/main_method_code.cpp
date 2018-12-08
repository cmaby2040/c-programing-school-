#include "player.h"
#include
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;


int main(){
	
	int gametype, numberplayers;
	string s, name,subName;
	bool doneLoop=false;
	while (!doneLoop){
		try{
		cout << " which type of game would you like to play 1)expert 2)regular \n";
		cin >>  gametype;
			if ((gametype!=1 || gametype!=2) && (gametype==1 || gametype!=2) && (gametype!=1 || gametype==2) ) {
				throw -1;
			}
		doneLoop=true;
		}catch(int){
			cout << "must be an interger value 1 or 2"<< endl;
			
		}
	}
	doneLoop=false;
	while (!doneLoop){
		try{
			cout << "how many player would you like between 2-4:" << endl; 
			cin >> numberplayers;
			cout<< numberplayers <<endl;
			if (numberplayers<2){
				throw -1;
			}if (numberplayers>4){
				throw -1;
			}
			doneLoop=true;
		}catch(int){
			cout << "must be an interger value between 2-4"<< endl;	
		}
	}
	
	for (int i=1; i<numberplayers+1;i++){
		cout << "type player " << i << " name." << endl;
		cin >> name;
		s+= name +" ";// us the space to differentiate names of strings
	}
	
	//create the Game g1();
	
	for(int i=0;i<numberplayers;++i){//creates each player
		int j;
		if (i==0){//parse string
			j=s.find_first_of(' ');
		}else{
			j=s.find_first_of(' ', j);
		}
		if(i==0){
			subName =s.substr(0,j);
		}else{
			subName =s.substr(1,j-1);
		}
		s=s.erase(0,j);//get rid of old nam
		
		Player::Side side; //creating each player object
		if (i==0){
			side = Player::Side::top;	
		}else if (i==1){
			side = Player::Side::bottom;	
		}else if (i==2){
			side = Player::Side::left;	
		}else{
			side = Player::Side::right;	
		}
		Player p1(subName, 0, 0, side);
		cout << p1;
		//game.addplayer(p1) //add player into game
	}
	/*
	while (!rules.gameOver()){
		//game.board.reset() //reset the cards that 
		for (int i=0 ; i<numberplayers ; ++i){
			//game.playerlist.setactive(true);
		}
		for (int i=0; i<numberplayers; ++i){// order is top,bootom left right
			//flip cards for each player temporarily
			//based on a time function
			//game.board.reset()
		}
		while(!rules.roundOver()){
			//cycle throught the active players flipping and testing cards
		}
	}
	
*/	
}
