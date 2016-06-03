//
// Dallas Dunnett
//
#include "MonopolyPos.h"
#include "enums.h"
#include "PairOfDice.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include <random>
#include <iomanip>



std::map<Place,int> _placeTouches // Initialize how often each place is touched to 0
{
	{ Place::AtlanticAvenue      , 0 },
	{ Place::BalticAvenue        , 0 },
	{ Place::BoardWalk           , 0 },
	{ Place::BORailroad          , 0 },
	{ Place::Chance_1            , 0 },
	{ Place::Chance_2            , 0 },
	{ Place::Chance_3            , 0 },
	{ Place::CommunityChest_1    , 0 },
	{ Place::CommunityChest_2    , 0 },
	{ Place::CommunityChest_3    , 0 },
	{ Place::ConnecticutAvenue   , 0 },
	{ Place::ElectricCompany     , 0 },
	{ Place::FreeParking         , 0 },
	{ Place::GO                  , 0 },
	{ Place::GOTOJAIL            , 0 },
	{ Place::IllinoisAvenue      , 0 },
	{ Place::IncomeTax           , 0 },
	{ Place::IndianiaAvenue      , 0 },
	{ Place::JustVisiting        , 0 },
	{ Place::KentuckyAvenue      , 0 },
	{ Place::LuxeryTax           , 0 },
	{ Place::MarvinGardens       , 0 },
	{ Place::MediteraneanAvenue  , 0 },
	{ Place::NewYorkAvenue       , 0 },
	{ Place::NorthCarolinaAvenue , 0 },
	{ Place::OrientalAvenue      , 0 },
	{ Place::PacificAvenue       , 0 },
	{ Place::ParkPlace           , 0 },
	{ Place::PennsylvaniaAvenue  , 0 },
	{ Place::PennsylvaniaRailroad, 0 },
	{ Place::ReadingRailroad     , 0 },
	{ Place::ShortLine           , 0 },
	{ Place::StatesAvenue        , 0 },
	{ Place::StCharlesPlace      , 0 },
	{ Place::StJamesPlace        , 0 },
	{ Place::TennesseAvenue      , 0 },
	{ Place::VentinorAvenue      , 0 },
	{ Place::VermontAvenue       , 0 },
	{ Place::VirginiaAvenue      , 0 },
	{ Place::WaterWorks          , 0 }
};


MonopolyPos::MonopolyPos() // Constructor
{
	srand(static_cast<unsigned int>(time(0)));
	_pos = Place::GO;
}

MonopolyPos::~MonopolyPos()// Deconstructor
{
}


Place MonopolyPos::goTo(Place p) // Sets position
{
	_pos = p;
	_placeTouches[Place(_pos)]++;
	return _pos;
}

void MonopolyPos::moveForward(int roll) // Moves forward spaces equal to number passed in
{
	int position = static_cast<int>(getPos()) + roll;
	if (position > 39)
	{
		position -= 40;
	}
	_placeTouches[Place(position)]++;
	_pos = static_cast<Place>(position);
}

void MonopolyPos::moveBackward(int back) // Moves backward a set number of spaces as there's only one way to move backward in Monopoly
{
	back = 3;
	int position = static_cast<int>(getPos()) - back;
	_placeTouches[Place(position)]++;
	_pos = static_cast<Place>(position);
}

Place MonopolyPos::nearestRailroad() // Tests and moves to the nearest railroad
{
	int position = static_cast<int>(getPos());
	if ((position - static_cast<int>(Place::ReadingRailroad)) > 0)
	{
		if ((position - static_cast<int>(Place::PennsylvaniaRailroad)) > 0)
		{
			if ((position - static_cast<int>(Place::BORailroad)) > 0)
			{
				if ((position - static_cast<int>(Place::ShortLine)) > 0)
				{
					position = static_cast<int>(Place::ReadingRailroad);
					return static_cast<Place>(position);
				}
				else
				{
					position = static_cast<int>(Place::ShortLine);
					return static_cast<Place>(position);
				}
			}
			else
			{
				position = static_cast<int>(Place::BORailroad);
				return static_cast<Place>(position);
			}
		}
		else
		{
			position = static_cast<int>(Place::PennsylvaniaRailroad);
			return static_cast<Place>(position);
		}
	}
	else
	{
		position = static_cast<int>(Place::ReadingRailroad);
		return static_cast<Place>(position);
	}
}

Place MonopolyPos::nearestUtility() // Tests and moves to the nearest utility
{
	int position = static_cast<int>(getPos());
	if ((position - static_cast<int>(Place::ElectricCompany)) > 0)
	{
		if ((position - static_cast<int>(Place::WaterWorks)) > 0)
		{
			position = static_cast<int>(Place::ElectricCompany);
			return static_cast<Place>(position);
		}
		else
		{
			position = static_cast<int>(Place::WaterWorks);
			return static_cast<Place>(position);
		}
	}
	else
	{
		position = static_cast<int>(Place::ElectricCompany);
		return static_cast<Place>(position);
	}
}

Place MonopolyPos::getPos() // returns the current position
{
	return _pos;
}

CommunityChest MonopolyPos::drawCommunityChest() // Draws and moves depending on card drawn
{
	int randNum = (rand() % 16) + 1;
	if(randNum == static_cast<int>(CommunityChest::GoTo_Jail))
	{
		//_inJail = true;
		_pos = Place::JustVisiting;
	}
	else if (randNum == static_cast<int>(CommunityChest::GoTo_Go))
	{
		_pos = Place::GO;
	}
	return static_cast<CommunityChest>(randNum);
}

Chance MonopolyPos::drawChance() // Draws and returns the card drawn
{
	int randNum = (rand() % 16) + 1;
	
	return static_cast<Chance>(randNum);
}

std::string MonopolyPos::placeToString(Place p) //to get the string version of the enum
{

	return _placeNames[p];
}

void MonopolyPos::results() // prints out how often each place is touched as a percentage
{
	for (auto e : _placeTouches)
	{
		std::cout << std::setw(25) << placeToString(e.first) << ": " << (((double)e.second / 1000000) * 100) << "%" << std::endl;
	}
		
}

void MonopolyPos::fillMaps() // fills _placeNames
{
	_placeNames.insert(std::pair<Place, std::string>(Place::AtlanticAvenue, "Atlantic Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::BalticAvenue, "Baltic Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::BoardWalk, "Board Walk"));
	_placeNames.insert(std::pair<Place, std::string>(Place::BORailroad, "B & O Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::Chance_1, "Chance"));
	_placeNames.insert(std::pair<Place, std::string>(Place::Chance_2, "Chance"));
	_placeNames.insert(std::pair<Place, std::string>(Place::Chance_3, "Chance"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CommunityChest_1, "Community Chest"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CommunityChest_2, "Community Chest"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CommunityChest_3, "Community Chest"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ConnecticutAvenue, "Connecticut Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ElectricCompany, "Electric Company"));
	_placeNames.insert(std::pair<Place, std::string>(Place::FreeParking, "Free Parking"));
	_placeNames.insert(std::pair<Place, std::string>(Place::GO, "Go"));
	_placeNames.insert(std::pair<Place, std::string>(Place::GOTOJAIL, "Go To Jail!"));
	_placeNames.insert(std::pair<Place, std::string>(Place::IllinoisAvenue, "Illinois Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::IncomeTax, "Income Tax"));
	_placeNames.insert(std::pair<Place, std::string>(Place::IndianiaAvenue, "Indiania Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::JustVisiting, "Just Visiting / Jail"));
	_placeNames.insert(std::pair<Place, std::string>(Place::KentuckyAvenue, "Kentucky Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::LuxeryTax, "Luxery Tax"));
	_placeNames.insert(std::pair<Place, std::string>(Place::MarvinGardens, "Marvin Gardens"));
	_placeNames.insert(std::pair<Place, std::string>(Place::MediteraneanAvenue, "Mediteranean Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::NewYorkAvenue, "New York Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::NorthCarolinaAvenue, "North Carolina Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::OrientalAvenue, "Oriental Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PacificAvenue, "Pacific Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ParkPlace, "Park Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PennsylvaniaAvenue, "Pennsylvania Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PennsylvaniaRailroad, "Pennsylvania Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ReadingRailroad, "Reading Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ShortLine, "Short Line"));
	_placeNames.insert(std::pair<Place, std::string>(Place::StatesAvenue, "States Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::StCharlesPlace, "St. Charles Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::StJamesPlace, "St. James Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::TennesseAvenue, "Tennesse Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::VentinorAvenue, "Ventinor Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::VermontAvenue, "Vermont Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::VirginiaAvenue, "Virginia Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::WaterWorks, "Water Works"));
}