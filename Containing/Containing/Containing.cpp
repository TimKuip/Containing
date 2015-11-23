// Containing.cpp : Defines the entry point for the console application.
//
#include "Afstandberekenaar.h"
#include "Voertuig.h"
#include "Schip.h"
#include "Trein.h"
#include "Vrachtwagen.h"
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Controller
{
public:
	string xmlfilename;
	XMLlezer xmllezer;
	Afstandberekenaar afstandberekenaar;
	Avg avg;
	Trein trein;
	Schip schip;
	Vrachtwagen vrachtwagen;
	Kraan kraan;
	Container container;

	void Start(string xmlfilename);
};

void Controller::Start(string xmlfilename)
{
}

int Main()
{

}