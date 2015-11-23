#include "stdafx.h"
#include "Trein.h"

Trein::Trein(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit):Voertuig(id, type, snelheidLeeg, snelheidBeladen, startLocatieX, startLocatieY, startLocatieZ, containerList, bestemming, isWachtend, maxCapaciteit)
{
}

void Trein::Verplaats(string start,string einde)
{
	ab.KortsteRoute(start, einde);
}

void Trein::Inladen()
{
}

void Trein::Uitladen(vector<string> containerIdList)
{
}

Trein::~Trein()
{
}
