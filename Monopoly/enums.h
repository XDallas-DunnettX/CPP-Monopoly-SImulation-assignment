//
// Dallas Dunnett
//
#pragma once
enum class Place
{
	GO = 0              ,
	MediteraneanAvenue  ,
	CommunityChest_1    ,
	BalticAvenue        ,
	IncomeTax           ,
	ReadingRailroad     ,
	OrientalAvenue      ,
	Chance_1            ,
	VermontAvenue       ,
	ConnecticutAvenue   , // Street 1 end
	JustVisiting        ,
	StCharlesPlace      ,
	ElectricCompany     ,
	StatesAvenue        ,
	VirginiaAvenue      ,
	PennsylvaniaRailroad,
	StJamesPlace        ,
	CommunityChest_2    ,
	TennesseAvenue      ,
	NewYorkAvenue       , // Street 2 end
	FreeParking         ,
	KentuckyAvenue      ,
	Chance_2            ,
	IndianiaAvenue      ,
	IllinoisAvenue      ,
	BORailroad          ,
	AtlanticAvenue      ,
	VentinorAvenue      ,
	WaterWorks          ,
	MarvinGardens       , // Street 3 end
	GOTOJAIL            ,
	PacificAvenue       ,
	NorthCarolinaAvenue ,
	CommunityChest_3    ,
	PennsylvaniaAvenue  ,
	ShortLine           ,
	Chance_3            ,
	ParkPlace           ,
	LuxeryTax           ,
	BoardWalk           , // Street 4 end
	Count // Place Count
};

enum class Chance
{
	GoTo_Nearest_Railroad_1 = 0, // Move cards
	GoTo_Nearest_Railroad_2,
	GoTo_Reading,
	GoTo_Illinois,
	GoTo_St_Charles,
	GoTo_Go,
	GoTo_BoardWalk,
	GoTo_Jail,
	GoTo_Three_Spaces_Back,
	GoTo_Nearest_Utility,
	Pay_Poor_Tax,  // Non-Move Cards
	Elected_Chairman,
	Houses_And_Hotels_Renovation,
	Bank_Pays_Dividend,
	Loan_Matures,
	Get_Out_Of_Jail_Free,
	Count // Card Count
};

enum class CommunityChest
{
	GoTo_Jail = 0,// Move cards
	GoTo_Go, 
	Pay_School_Tax,// Non-Move cards
	Service_Reward1,
	Service_Reward2,
	Recieve_Fifth_From_Each_Player,
	XMas_Fund,
	Life_Insurance,
	Doctor_Fee,
	Income_Tax_Return,
	Bank_Error,
	Property_Tax,
	Hospital_Tax,
	Get_Out_Of_Jail_Free,
	Beauty_Contest,
	Inherit,
	Count // Card Count

};