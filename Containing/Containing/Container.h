#pragma once
#include <string>
#include <vector>

using namespace std;

class Container
{

public:
	/*
	string aankomstDatum;
	double aankomstTijdVan;
	double aankomstTijdTot;
	string aankomstVervoer;
	string aankomstBedrijf;
	int x;
	int y;
	int z;
	string eigenaar;
	int containerNr;
	int vertrekDatum;
	double vertrekTijdVan;
	double vertrekTijdTot;
	string vertrekVervoer;
	string vertrekBedrijf;
	double lengte;
	double breedte;
	double hoogte;
	int gewichtLeeg;
	int gewicht;
	string inhoudNaam;
	string inhoudSoort;
	string gevaar;
	string iso;
	*/

	Container(string aankomstDatum, double aankomstTijdVan, double aankomstTijdTot, string aankomstVervoer, string aankomstBedrijf, int x, int y, int z, string eigenaar, int containerNr, int vertrekDatum, double vertrekTijdVan, double vertrekTijdTot, string vertrekVervoer, string vertrekBedrijf, double lengte, double breedte, double hoogte, int gewichtLeeg, int gewicht, string inhoudNaam, string inhoudSoort, string gevaar, string iso);
	int GetContainerNr();
	~Container();
};