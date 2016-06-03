//
// Dallas Dunnett
//
#pragma once
#include "enums.h"
#include <string>
#include <map>

class MonopolyPos
{
public:

	MonopolyPos();
	~MonopolyPos();

	Place goTo(Place);
	void moveForward(int);
	void moveBackward(int);
	Place nearestRailroad();
	Place nearestUtility();
	Place getPos();
	CommunityChest drawCommunityChest();
	Chance drawChance();
	std::string placeToString(Place);
	void results();
	void fillMaps();

private:

	Place _pos;
	//bool _inJail = false;
	std::map<Place, int> _placeTouches;
	std::map<Place, std::string> _placeNames;
};

