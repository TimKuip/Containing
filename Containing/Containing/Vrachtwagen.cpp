#include "stdafx.h"
#include "Vrachtwagen.h"


Vrachtwagen::Vrachtwagen(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit) :Voertuig(id, type, snelheidLeeg, snelheidBeladen, startLocatieX, startLocatieY, startLocatieZ, containerList, bestemming, isWachtend, maxCapaciteit)
{
	// hier moet meschien de declaratie van de variabelen, weet nog niet zeker omdat deze klasse van voertuig erft en daar worden
	// ze ook al een keer gedeclareerd
}

void Vrachtwagen::Verplaats(double x, double y, double z)
{
	//again, allemaal theoretisch spul dat ik uit mijn duim zuich totdat ik echt weet wat ik allemaal in de functie wil
	KorsteRoute(x, y, z);
}

void Vrachtwagen::Inladen()
{
	//again, allemaal theoretisch spul dat ik uit mijn duim zuich totdat ik echt weet wat ik allemaal in de functie wil
	
}

void Vrachtwagen::Uitladen(vector<string> containerIdList)
{
	//again, allemaal theoretisch spul dat ik uit mijn duim zuich totdat ik echt weet wat ik allemaal in de functie wil

}
Vrachtwagen::~Vrachtwagen()
{
	//geen idee hoe deconstructors werken, later toevoegen

}


