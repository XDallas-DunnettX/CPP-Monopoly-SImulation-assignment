//
// Dallas Dunnett
//
#include "PairOfDice.h"
#include <cstdlib>
#include <ctime>



PairOfDice::PairOfDice() //CTOR
{
	srand(static_cast<unsigned int>(time(0)));
}


PairOfDice::~PairOfDice() //DTOR
{
}

int PairOfDice::roll() // generates two random numbers between 1 and 6, adds them and returns them to source
{
	int roll = (rand() % 6) + 1;
	int roll2 = (rand() % 6) + 1;
	_dice1 = roll;
	_dice2 = roll2;
	int rollReturn = roll + roll2;
	return rollReturn;
}

bool PairOfDice::isDouble() // Checks if rolled die are doubles
{
	if (_dice1 == _dice2)
	{
		return true;
	}
	else
	{
		return false;
	}
}