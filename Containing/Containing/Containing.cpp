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
	

public:
	KortstePad() {
		//inlezen locaties en de routes
		kortsteroute();
	}

	int afstand(string plaats1, string plaats2) {
		return afstanden[{plaats1, plaats2}];

	}

	

	
};




