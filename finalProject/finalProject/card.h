#pragma once
#include <iostream>
#include <string>

class Card {
	Card(FaceAnimal _animal, FaceBackground _background);
	
public:
	//convert this to FaceAnimal
	operator cardToFaceAnimal();
	//convert this to FaceBackground
	operator cardToFaceBackground();
	//return number of rows
	int getNRows();
	//row to string
	std::string c(int _row);
};