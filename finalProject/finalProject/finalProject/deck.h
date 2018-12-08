#pragma once

#include <stdio.h>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
#ifndef DECK_H
#define DECK_H

template <typename C>
class Deck {
public:
	//shuffles the cards
	virtual void shuffle()=0;
	//returns next card pointer if next!=null
	virtual C* getNext() const=0;
	//returns true if deck is empty, else return false
	virtual bool isEmpty() const=0;
	//dtor
	virtual ~Deck() {};
};
#endif