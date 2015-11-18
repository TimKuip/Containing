#include "stdafx.h"
#include "Voertuig.h"


Voertuig::Voertuig(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit)
{
	Id = id;
	Type = type;
	SnelheidLeeg = snelheidLeeg;
	SnelheidBeladen = snelheidBeladen;
	StartLocatieX = startLocatieX;
	StartLocatieY = startLocatieY;
	StartLocatieZ = startLocatieZ;
	ContainerList = containerList;
	Bestemming = bestemming;
	IsWachtend = isWachtend;
	MaxCapaciteit = maxCapaciteit;
}

// !!! een andere mogelijkheid is om de functies leeg te laten en de specifieke objecten ze te laten Overriden om er hun eigen functionaliteit aan te geven !!!
// !!! niet alle voertuigen zullen op dezelfde manier werken, iets om in het achterhoofd te houden !!!


void Voertuig::Verplaats(double x, double y, double z)
{
	//!!! Deze functie is nu virtual abstract wat inhoud dat zijn functionaliteit van de klasse afhangt die hem erft !!!
	//dit is puur speculatie aangezien deze functies nog niet gemaakt zijn of er is nog niet bekend hoe deze gaan werken
	//bedoeling is dat Verplaats() het voertuig met of zonder container verplaats via de kortste route naar zijn bestemming
}

void Voertuig::Inladen()
{
	//!!! Deze functie is nu virtual abstract wat inhoud dat zijn functionaliteit van de klasse afhangt die hem erft !!!
	//dit is puur speculatie aangezien deze functies nog niet gemaakt zijn of er is nog niet bekend hoe deze gaan werken
	//bedoeling is dat Inladen() wacht tot het voertuig ingeladen is
}

void Voertuig::Uitladen(vector<string> containerIdList)
{
	//!!! Deze functie is nu virtual abstract wat inhoud dat zijn functionaliteit van de klasse afhangt die hem erft !!!
	//dit is puur speculatie aangezien deze functies nog niet gemaakt zijn of er is nog niet bekend hoe deze gaan werken
	//bedoeling is dat Uitladen() de container(s) afgeeft aan een ander voertuig
}


Voertuig::~Voertuig()
{
	//!!! kan zijn dat Voertuig een lege deconstructor krijgt omdat ie virtual is, weet niet zeker !!!
	//geen idee hoe deconstructors werken, later toevoegen
}
