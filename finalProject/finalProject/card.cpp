#include "card.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

int Card::getNRows() {
	return this->numRows;
}
char Card::getAnimal() const {
	char a;
	if (this->animal == Penguin) a = 'P';
	else if (this->animal == Sheep) a = 'S';
	else if (this->animal == Donkey) a = 'D';
	else if (this->animal == Gorilla) a = 'G';
	else if (this->animal== Fish) a = 'F';

	return a;
}

char Card::getColor() const {
	char c;
	if (this->background==red) c='R';
	else if (this->background == orange) c = 'O';
	else if (this->background == yellow) c = 'Y';
	else if (this->background == green) c = 'G';
	else if (this->background == blue) c = 'B';

	return c;
}

Card::Card(FaceAnimal _animal, FaceBackground _background) : 
	animal{ _animal }, background{_background}{
	char _color = this->getColor();
	char _animalType = this->getAnimal();
	*row = { _color, _color, _color };
	*(row+1)= { _color, _animalType, _color };
	*(row+2)= { _color, _color, _color };
}

Card::~Card()
{
}

string Card::operator()(int _rowNum) const {
	string _rowString = *(row + _rowNum);
	return _rowString;
}

Card::operator FaceAnimal() const {
	return animal;
}

Card::operator FaceBackground() const {
	return background;
}

