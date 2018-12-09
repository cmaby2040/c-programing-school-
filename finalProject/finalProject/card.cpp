#include "card.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
using std::ostream;
using std::string;
using std::cout;
using std::cin;


int Card::getNRows() {
	return this->numRows;
}
char Card::getAnimal() const {
	char a;
	//check each case
	if (animal == Card::FaceAnimal::crab) a = 'C';
	else if (animal == Card::FaceAnimal::penguin) a = 'P';
	else if (animal == Card::FaceAnimal::octopus) a = 'O';
	else if (animal == Card::FaceAnimal::turtle) a = 'T';
	else if (animal== Card::FaceAnimal::walrus) a = 'W';
	//return char a
	return a;
}

char Card::getColor() const {
	char c;
	//check each case
	if (background == Card::FaceBackground::red) c='R';
	else if (background == Card::FaceBackground::green) c = 'G';
	else if (background == Card::FaceBackground::purple) c = 'P';
	else if (background == Card::FaceBackground::blue) c = 'B';
	else if (background == Card::FaceBackground::yellow) c = 'Y';
	//return char c
	return c;
}

Card::Card(FaceAnimal _animal, FaceBackground _background) : 
	animal{ _animal }, background{ _background }{
	//get char of animal and color
	char _color = this->getColor();
	char _animalType = this->getAnimal();
	//set string values
	std::string temp;
	temp += _color;
	temp += _color;
	temp += _color;
	temp += _color;
	temp += _animalType;
	temp += _color;
	temp += _color;
	temp += _color;
	temp += _color;
	//set row value
	row = temp;
}

Card::~Card()
{
}

string Card::operator()(int _rowNum) const {
	string _rowString;
	//set each row for the string
	for (int i = 0; i < 3; i++) {
		_rowString += row[3*_rowNum+i];
	}
	return _rowString;
}

//animal operator
Card::operator FaceAnimal() const {
	return animal;
}

//color operator
Card::operator FaceBackground() const {
	return background;
}
ostream& operator<<(ostream& _oStream, const Card& _card) {
	_oStream << _card.getColor() << _card.getColor() << _card.getColor() << std::endl;
	_oStream << _card.getColor() << _card.getAnimal() << _card.getColor() << std::endl;
	_oStream << _card.getColor() << _card.getColor() << _card.getColor() << std::endl;
	return _oStream;

}