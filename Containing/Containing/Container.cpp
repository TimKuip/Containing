#include "stdafx.h"
#include "Container.h"


Container::Container(string aankomstDatum, double aankomstTijd, double uitlaadTijd, string aankomstVervoer, string aankomstBedrijf, int positieX, int positieY, int positieZ, string eigenaar, int containerNr, int vertrekDatum, double inlaadStart, double inlaadEind, int vertrekVervoer, int vertrekBedrijf, double lengte, double breedte, double hoogte, int leegGewicht, int inhoudGewicht, string inhoudNaam, string inhoudSoort, string gevaar, string ISO)
{

	AankomstDatum = aankomstDatum;
	AankomstTijd = aankomstTijd;
	UitlaadTijd = uitlaadTijd;
	AankomstVervoer = aankomstVervoer;
	AankomstBedrijf = aankomstBedrijf;
	PositieX = positieX;
	PositieY = positieY;
	PositieZ = positieZ;
	Eigenaar = eigenaar;
	ContainerNr = containerNr;
	VertrekDatum = vertrekDatum;
	InlaadStart = inlaadStart;
	InlaadEind = inlaadEind;
	VertrekVervoer = vertrekVervoer;
	VertrekBedrijf = vertrekBedrijf;
	Lengte = lengte;
	Breedte = breedte;
	Hoogte = hoogte;
	LeegGewicht = leegGewicht;
	InhoudGewicht = inhoudGewicht;
	InhoudNaam = inhoudNaam;
	InhoudSoort = inhoudSoort;
	Gevaar = gevaar;
	ISO = ISO;




}



//Verder geen functies? Word puur verplaatst door voortuigen?

Container::~Container()
{
	//Iemand werking van deconstructors? 
}
