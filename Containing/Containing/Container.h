#pragma once
#include <string>
#include <vector>
using namespace std;

class Container
{

public: 
		string AankomstDatum;
		double AankomstTijd;
		double UitlaadTijd;
		string AankomstVervoer;
		string AankomstBedrijf;
		int PositieX;
		int PositieY;
		int PositieZ;
		string Eigenaar;
		int ContainerNr;
		int VertrekDatum;
		double InlaadStart;
		double InlaadEind;
		int VertrekVervoer;
		int VertrekBedrijf;
		double Lengte;
		double Breedte;
		double Hoogte;
		int LeegGewicht;
		int InhoudGewicht;
		string InhoudNaam;
		string InhoudSoort;
		string Gevaar;
		string ISO;

		Container(string aankomstDatum, double aankomstTijd, double uitlaadTijd, string aankomstVervoer, string aankomstBedrijf, int positieX, int positieY, int positieZ, string eigenaar, int containerNr, int vertrekDatum, double inlaadStart, double inlaadEind, int vertrekVervoer, int vertrekBedrijf, double lengte, double breedte, double hoogte, int leegGewicht, int inhoudGewicht, string inhoudNaam, string inhoudSoort, string gevaar, string ISO);
		~Container();
