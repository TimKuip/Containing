#pragma once
using namespace std;
#include <string>
#include <vector>

class XMLlezen
{
public:
	XMLlezen(string file);
	vector<string>load_xml(string file);
};