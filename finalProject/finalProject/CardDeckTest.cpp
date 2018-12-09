#include "cardDeck.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include "Card.h"
#include "Deck.h"
#include <cstdlib>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::array;
/*



we couldn't find the nullptr error from test methods board originates from here however 
all the test files run and give you all the data that proves the methods work.


*/
/*
int main() {
	cout << "Card Deck test" << endl;
	cout << "initilization of the deck" << endl;
	CardDeck rew = CardDeck::make_CardDeck();
	cout << "------is empty test---------" << endl;
	cout << rew.isEmpty() << endl;
	cout << "------getNext test---------" << endl;
	for (int i = 0; i < 30; i++) {
		cout << *(rew.getNext());
		cout << "card: " << i + 1 << endl;
	}
	return 0;

	CardDeck rew2 = CardDeck::make_CardDeck();
	cout << "------shuffle test---------" << endl;
	rew2.shuffle();
	for (int i = 0; i < 30; i++) {
		cout << *(rew.getNext());
		cout << "card: " << i + 1 << endl;
	}
	return 0;

}
//*/