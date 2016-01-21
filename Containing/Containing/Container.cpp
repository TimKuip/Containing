#include "stdafx.h"
#include "Container.h"

string AankomstDatum;
double AankomstTijdVan;
double AankomstTijdTot;
string AankomstVervoer;
string AankomstBedrijf;
int X;
int Y;
int Z;
string Eigenaar;
int containerNr;
string VertrekDatum;
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

Container::Container() 
{

}

void Container::SetContainerNr(int containernr)
{
	containerNr = containernr;
}

void Container::SetVertrekDatum(string vertrekdatum)
{
	VertrekDatum = vertrekdatum;
}

void Container::SetVertrekTijdVan(double vertrektijdvan)
{
	VertrekTijdVan = vertrektijdvan;
}

void Container::SetVertrekTijdTot(double vertrektijdtot)
{
	VertrekTijdTot = vertrektijdtot;
}

void Container::SetVertrekVervoer(string vertrekvervoer)
{
	VertrekVervoer = vertrekvervoer;
}

void Container::SetVertrekBedrijf(string vertrekbedrijf)
{
	VertrekBedrijf = vertrekbedrijf;
}

void Container::SetLengte(double lengte)
{
	Lengte = lengte;
}

void Container::SetBreedte(double breedte)
{
	Breedte = breedte;
}

void Container::SetHoogte(double hoogte)
{
	Hoogte = hoogte;
}

void Container::SetGewichtLeeg(int gewichtleeg)
{
	GewichtLeeg = gewichtleeg;
}

void Container::SetGewicht(int gewicht)
{
	Gewicht = gewicht;
}

void Container::SetInhoudNaam(string inhoudnaam)
{
	InhoudNaam = inhoudnaam;
}

void Container::SetInhoudSoort(string inhoudsoort)
{
	InhoudSoort = inhoudsoort;
}

void Container::SetGevaar(string gevaar)
{
	Gevaar = gevaar;
}

void Container::SetIso(string iso)
{
	ISO = iso;
}

void Container::SetAankomstDatum(string aankomstdatum)
{
	AankomstDatum = aankomstdatum;
}

void Container::SetAankomstTijdVan(double aankomsttijdvan)
{
	AankomstTijdVan = aankomsttijdvan;
}

void Container::SetAankomstTijdTot(double aankomsttijdtot)
{
	AankomstTijdTot = aankomsttijdtot;
}

void Container::SetAankomstVervoer(string aankomstvervoer)
{
	AankomstVervoer = aankomstvervoer;
}

void Container::SetAankomstBedrijf(string aankomstbedrijf)
{
	AankomstBedrijf = aankomstbedrijf;
}

void Container::SetX(int x)
{
	X = x;
}

void Container::SetY(int y)
{
	Y = y;
}

void Container::SetZ(int z)
{
	Z = z;
}

void Container::SetEigenaar(string eigenaar)
{
	Eigenaar = eigenaar;
}


bool Container::operator< (Container &other) const 
{
	return AankomstDatum < other.GetAankomstDatum();
}

int Container::GetContainerNr()
{
	return containerNr;
}

int Container::GetGewicht()
{
	return Gewicht;
}

string Container::GetAankomstDatum()
{
	return AankomstDatum;
}

double Container::GetAankomstTijd()
{
	return AankomstTijdVan;
}

string Container::GetAankomstVervoer()
{
	return AankomstVervoer;
}
double Container::GetAankomstTijdTot()
{
	return AankomstTijdTot;
}
double Container::GetVertrekTijdVan()
{
	return VertrekTijdVan;
}
string Container::GetVertrekDatum()
{
	return VertrekDatum;
}
string Container::GetVertrekVervoer()
{
	return VertrekVervoer;
}

Container::~Container()
{
	//Iemand werking van deconstructors? 
}
