#pragma once

class Deck {
public:
	virtual void shuffle();
	virtual C* getNext();
	virtual bool isEmpty();
};