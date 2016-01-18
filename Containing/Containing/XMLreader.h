#pragma once
using namespace std;
#include <string>
#include <vector>
#include "Container.h"

class XMLlezen
{
public:
	XMLlezen();
	vector<Container> load_xml(vector<string> files);
};