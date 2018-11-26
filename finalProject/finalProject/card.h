#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
using std::string;
using std::cout;
using std::cin;
#ifndef CARD_H
#define CARD_H

class CardDeck;
class Card {
public:
	//FaceAnimal enumerations
	enum FaceAnimal {
		Penguin, Sheep, Donkey, Fish, Gorilla
	};
	//FaceBackground enumerations
	enum FaceBackground {
		red, orange, yellow, green, blue
	};
	//row string operator
	string operator() (int _row) const;
	//FaceAnimal and FaceBackground Operators
	operator FaceAnimal() const;
	operator FaceBackground() const;
private:
	friend class CardDeck;
	//variables
	const int numRows = 3;
	FaceAnimal animal;
	FaceBackground background;
	std::string* row;
	//return num of rows
	int getNRows();
	//return animal character
	char getAnimal() const;
	//return color ccharacter
	char getColor() const;
	//ctor
	Card(FaceAnimal _animal, FaceBackground _background);
	//dtor
	~Card();
};
#endif