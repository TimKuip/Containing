#pragma once
#include <string>
#include <vector>
#include "Container.h"
using namespace std;

class Voertuig
{	

public:
	string Id;
	string Type;
	double SnelheidLeeg;
	double SnelheidBeladen;
	double StartLocatieX;
	double StartLocatieY;
	double StartLocatieZ;
	vector<Container> ContainerList; // ContainerList bevat objecten genaamt Containers, deze zijn nog niet gedefineerd
	string Bestemming;
	bool IsWachtend;
	int MaxCapaciteit;
	
	Voertuig(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit);
	// ik heb de functies virtual abstract gemaakt. dit houd in dat ze geen functionaliteit hebben in de Ouderklasse
	//maar elke kind klasse die hier van erft kan er zijn eigen functionaliteit geven
	virtual void Verplaats(string start, string einde)=0;
	virtual void Inladen()=0;
	virtual void Uitladen(vector<string> containerIdList)=0;
	virtual~Voertuig();
};

