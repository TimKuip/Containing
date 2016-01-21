#pragma once
#include <string>
#include <vector>

using namespace std;

class Container
{
private:
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
	
public:
	void SetAankomstDatum(string aankomstdatum);
	void SetAankomstTijdVan(double aankomsttijdvan);
	void SetAankomstTijdTot(double aankomsttijdtot);
	void SetAankomstVervoer(string aankomstvervoer);
	void SetAankomstBedrijf(string aankomstbedrijf);
	void SetX(int x);
	void SetY(int y);
	void SetZ(int z);
	void SetEigenaar(string eigenaar);
	void SetContainerNr(int containernr);
	void SetVertrekDatum(string vertrekdatum);
	void SetVertrekTijdVan(double vertrektijdvan);
	void SetVertrekTijdTot(double vertrektijdtot);
	void SetVertrekVervoer(string vertrekvervoer);
	void SetVertrekBedrijf(string vertrekbedrijf);
	void SetLengte(double lengte);
	void SetBreedte(double breedte);
	void SetHoogte(double hoogte);
	void SetGewichtLeeg(int gewichtleeg);
	void SetGewicht(int gewicht);
	void SetInhoudNaam(string inhoudnaam);
	void SetInhoudSoort(string inhoudsoort);
	void SetGevaar(string gevaar);
	void SetIso(string iso);
		
	int GetContainerNr();
	int GetGewicht();
	string GetAankomstDatum();
	double GetAankomstTijd();
	string GetAankomstVervoer();
	double GetAankomstTijdTot();
	double GetVertrekTijdVan();
	string GetVertrekVervoer();
	string GetVertrekDatum();
	bool operator< (Container &other) const;
	Container();
	~Container();
};