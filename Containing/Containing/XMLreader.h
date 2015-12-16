#pragma once
using namespace std;

class XMLlezen
{
public:
	XMLlezen(string file, string name);
	vector<string>load_xml(string file, string name);
};