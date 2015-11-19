#include "stdafx.h"
#include "Afstandberekenaar.h"

Afstandberekenaar::Afstandberekenaar(string plaats1, string plaats2)
{
	//inlezen locaties en de routes
	KortsteRoute();
	Route(plaats1, plaats2);
}

int Afstandberekenaar::Afstand(string plaats1, string plaats2) 
{
	return afstanden[{plaats1, plaats2}];
}

string Afstandberekenaar::Route(string plaats1, string plaats2)
{
	string ret;
	string snelsteRoute = kortsteroutes[{plaats1, plaats2}];
	if (snelsteRoute == "")
		ret += (plaats1 + " > " + plaats2);
	else
		ret += (plaats1 + snelsteRoute + plaats2);
	return ret;
}

void Afstandberekenaar::KortsteRoute()
{
	for (auto k : plaatsen) {
		for (auto i : plaatsen) {
			for (auto j : plaatsen) {
				if (afstanden[{i, k}] + afstanden[{k, j}] < afstanden[{i, j}]) {
					afstanden[{i, j}] = afstanden[{i, k}] + afstanden[{k, j}];
					//plaats1 == i;
					//plaats2 == j;
					if (kortsteroutes[{i, k}] == "" && kortsteroutes[{k, j}] == "")
						kortsteroutes[{i, j}] = " > " + k + " > ";
					else if (kortsteroutes[{i, k}] == "")
						kortsteroutes[{i, j}] = " > " + k + " > " + kortsteroutes[{k, j}] + " > ";
					else if (kortsteroutes[{k, j}] == "")
						kortsteroutes[{i, j}] = " > " + kortsteroutes[{i, k}] + " > " + k + " > ";
				}
			}
		}
	}
}


Afstandberekenaar::~Afstandberekenaar()
{
	
}

