//
// Dallas Dunnett
//
#include <iostream>
#include "MonopolyPos.h"
#include "PairOfDice.h"
#include "enums.h"



int main()
{
	int doubles = 0;
	int rolls = 0;
	int rollVal = 0;
	PairOfDice die;
	Chance Ccard;
	CommunityChest ComCard;
	MonopolyPos position;

	position.fillMaps();

	while (rolls < 1000000)
	{
		rollVal = die.roll();
		if (die.isDouble())
		{
			doubles++;
			if (doubles == 3)
			{
				position.goTo(Place::JustVisiting);
				doubles = 0;
			}			
		}
		else
		{
			doubles = 0;
		}

		position.moveForward(rollVal);

		if (position.getPos() == Place::Chance_1 || position.getPos() == Place::Chance_2 || position.getPos() == Place::Chance_3)
		{
			Ccard = position.drawChance();

			if (Ccard == Chance::GoTo_Nearest_Railroad_1 || Ccard == Chance::GoTo_Nearest_Railroad_2)
			{
				position.goTo(position.nearestRailroad());
			}
			else if (Ccard == Chance::GoTo_Reading)
			{
				position.goTo(Place::ReadingRailroad);
			}
			else if (Ccard == Chance::GoTo_Illinois)
			{
				position.goTo(Place::IllinoisAvenue);
			}
			else if (Ccard == Chance::GoTo_St_Charles)
			{
				position.goTo(Place::StCharlesPlace);
			}
			else if (Ccard == Chance::GoTo_Go)
			{
				position.goTo(Place::GO);
			}
			else if (Ccard == Chance::GoTo_BoardWalk)
			{
				position.goTo(Place::BoardWalk);
			}
			else if (Ccard == Chance::GoTo_Jail)
			{
				position.goTo(Place::JustVisiting);
			}
			else if (Ccard == Chance::GoTo_Three_Spaces_Back)
			{
				position.moveBackward(3);
			}
			else if (Ccard == Chance::GoTo_Nearest_Utility)
			{
				position.goTo(position.nearestUtility());
			}

		}

		else if (position.getPos() == Place::CommunityChest_1 || position.getPos() == Place::CommunityChest_2 || position.getPos() == Place::CommunityChest_3)
		{

			ComCard = position.drawCommunityChest();

			if (ComCard == CommunityChest::GoTo_Jail)
			{
				position.goTo(Place::JustVisiting);
			}

			else if (ComCard == CommunityChest::GoTo_Go)
			{
				position.goTo(Place::GO);
			}
		}
		rolls++;
	}
	position.results();
	system("pause");
}