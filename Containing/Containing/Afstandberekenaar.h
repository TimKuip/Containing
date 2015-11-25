#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Afstandberekenaar
{
private:
	const int verweg = 1000000;
	vector<string> plaatsen{"kraan","boot","opslag"};
	map<pair<string, string>, int> afstanden;
	map<pair<string, string>, string> kortsteroutes;
public:
	Afstandberekenaar();
	int Afstand(string plaats1, string plaats2);
	string Route(string plaats1, string plaats2);
	string KortsteRoute(string plaats1, string plaats2);
	~Afstandberekenaar();

};

