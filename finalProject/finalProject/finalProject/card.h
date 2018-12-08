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
	enum class FaceAnimal {
		crab=0, 
		penguin, 
		octopus, 
		turtle, 
		walrus
	};
	
	//FaceBackground enumerations
	enum class FaceBackground {
		red=0, 
		green, 
		purple, 
		blue, 
		yellow
	};

	
	//row string operator
	string operator() (int _row) const;
	//FaceAnimal and FaceBackground Operators
	operator FaceAnimal() const;
	operator FaceBackground() const;
	//dtor
	~Card();
private:
	friend class CardDeck;
	//variables
	const int numRows = 3;
	FaceAnimal animal;
	FaceBackground background;
	std::string row = "";
	//return num of rows
	int getNRows();
	//return animal character
	char getAnimal() const;
	//return color ccharacter
	char getColor() const;
	//ctor
	Card(FaceAnimal _animal, FaceBackground _background);
	Card() = default;
};
#endif