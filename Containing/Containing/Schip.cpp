#include "stdafx.h"
#include "Schip.h"

Schip::Schip(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit):Voertuig(id, type, snelheidLeeg, snelheidBeladen, startLocatieX, startLocatieY, startLocatieZ, containerList, bestemming, isWachtend, maxCapaciteit)
{
}

void Schip::Verplaats(double x, double y, double z)
{
}

void Schip::Inladen()
{
}

void Schip::Uitladen(vector<string> containerIdList)
{
}

Schip::~Schip()
{
}
