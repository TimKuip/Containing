#pragma once
#include "Voertuig.h"
class Trein :public Voertuig //trein is een voertuig
{
public:
	Trein(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit);
	void Verplaats(double x, double y, double z);
	void Inladen();
	void Uitladen(vector<string> containerIdList);
	~Trein();
};

