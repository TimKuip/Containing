// Containing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;



class KortstePad
{
private:
	const int verweg = 1000000;
	vector<string> plaatsen;
	map<pair<string, string>, int> afstanden;
	map<pair<string, string>, string> kortsteroutes;

public:
	KortstePad() {
		//inlezen locaties en de routes
		kortsteroute();
	}

	int afstand(string plaats1, string plaats2) {
		return afstanden[{plaats1, plaats2}];

	}

	string route(string plaats1, string plaats2) {
		string ret;
		string snelsteRoute = kortsteroutes[{plaats1, plaats2}];
		if (snelsteRoute == "")
			ret += (plaats1 + " > " + plaats2);
		else
			ret += (plaats1 + snelsteRoute + plaats2);
		return ret;
	}

	void kortsteroute() {
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
};

string vraag(string prompt) {
	cout << prompt << endl;
	string p3;
	cin >> p3;
	return p3;
}



