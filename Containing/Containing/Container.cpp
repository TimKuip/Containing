#include "stdafx.h"
#include "Container.h"

//Verder geen functies? Word puur verplaatst door voortuigen?
string AankomstDatum;
double AankomstTijdVan;
double AankomstTijdTot;
string AankomstVervoer;
string AankomstBedrijf;
int X;
int Y;
int Z;
string Eigenaar;
int ContainerNr;
int VertrekDatum;
double VertrekTijdVan;
double VertrekTijdTot;
string VertrekVervoer;
string VertrekBedrijf;
double Lengte;
double Breedte;
double Hoogte;
int GewichtLeeg;
int Gewicht;
string InhoudNaam;
string InhoudSoort;
string Gevaar;
string ISO;

Container::Container(string aankomstDatum, double aankomstTijdVan, double aankomstTijdTot, string aankomstVervoer, string aankomstBedrijf, int x, int y, int z, string eigenaar, int containerNr, int vertrekDatum, double vertrekTijdVan, double vertrekTijdTot, string vertrekVervoer, string vertrekBedrijf, double lengte, double breedte, double hoogte, int gewichtLeeg, int gewicht, string inhoudNaam, string inhoudSoort, string gevaar, string iso)
{
	AankomstDatum = aankomstDatum;
	AankomstTijdVan = aankomstTijdVan;
	AankomstTijdTot = aankomstTijdTot;
	AankomstVervoer = aankomstVervoer;
	AankomstBedrijf = aankomstBedrijf;
	X = x;
	Y = y;
	Z = z;
	Eigenaar = eigenaar;
	ContainerNr = containerNr;
	VertrekDatum = vertrekDatum;
	VertrekTijdVan = vertrekTijdVan;
	VertrekTijdTot = vertrekTijdTot;
	VertrekVervoer = vertrekVervoer;
	VertrekBedrijf = vertrekBedrijf;
	Lengte = lengte;
	Breedte = breedte;
	Hoogte = hoogte;
	GewichtLeeg = gewichtLeeg;
	Gewicht = gewicht;
	InhoudNaam = inhoudNaam;
	InhoudSoort = inhoudSoort;
	Gevaar = gevaar;
	ISO = iso;
}

int Container::GetContainerNr()
{
	return ContainerNr;
}

Container::~Container()
{
	//Iemand werking van deconstructors? 
}
