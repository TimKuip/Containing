#pragma once
#include "Voertuig.h"
#include <string>
using namespace std;

class Vrachtwagen : public Voertuig //Vrachtwagen is een voertuig
{
public:
	Vrachtwagen(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit);
	void Verplaats(double x, double y, double z);
	void Inladen();
	void Uitladen(vector<string> containerIdList);
	~Vrachtwagen();
};

