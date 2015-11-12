#pragma once
#include <string>
#include <vector>
using namespace std;

class Voertuig
{
private:
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

public:
	Voertuig(string id, string type, double snelheidLeeg, double snelheidBeladen, double startLocatieX, double startLocatieY, double startLocatieZ, vector<Container> containerList, string bestemming, bool isWachtend, int maxCapaciteit);
	void Verplaats(double x, double y, double z);
	void Inladen();
	void Uitladen(vector<string> containerIdList);
	~Voertuig();
};

