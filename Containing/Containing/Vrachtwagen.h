#pragma once
#include "Voertuig.h"
#include "Afstandberekenaar.h"
#include <string>
using namespace std;

class Vrachtwagen : public Voertuig //Vrachtwagen is een voertuig
{
public:
	Afstandberekenaar ab;
	Vrachtwagen(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit);
	void Verplaats(string start, string einde);
	void Inladen();
	void Uitladen(vector<string> containerIdList);
	~Vrachtwagen();
};

