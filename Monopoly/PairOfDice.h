//
// Dallas Dunnett
//
#pragma once
class PairOfDice
{
public:
	PairOfDice();
	~PairOfDice();
	int roll();
	bool isDouble();

private:
	bool _double;
	int _dice1;
	int _dice2;
};

