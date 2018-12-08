#include "reward.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

Reward::Reward(Rubies _rubyValue) : rubyValue{_rubyValue} {}

Reward::operator int() const
{
	int i = this->rubyValue;
	return i;
}

Reward::~Reward()
{
	delete this;
}

ostream & operator<<(ostream & _oStream, const Reward & _reward)
{
	_oStream << "reward value is" << endl;
	_oStream << _reward.rubyValue << endl;
	return _oStream;
}

