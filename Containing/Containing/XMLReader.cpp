// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#import <msxml6.dll>
using namespace MSXML2;
#include <vector>
#include <string>
#include <iostream>
using namespace std;





class XMLlezen
{
public:
	vector<string>load_xml(string file, string name);
	
	XMLlezen(string file, string name)
	{
		load_xml(file, name);
	}
	
};

vector<string> XMLlezen::load_xml(string file, string name)
{
	vector<string> app_model;

	CoInitialize(NULL);

	string aankomstdatum;
	string vertrekdatum;

	//read XML
	MSXML2::IXMLDOMDocumentPtr spXMLDoc;
	spXMLDoc.CreateInstance(__uuidof(MSXML2::DOMDocument60));
	spXMLDoc->load(file.c_str());
	MSXML2::IXMLDOMElementPtr spRoot = spXMLDoc->documentElement; //root node

	if (spRoot->nodeName == (_bstr_t)"recordset")
	{
		MSXML2::IXMLDOMNodeListPtr recordNodeList = spRoot->childNodes;
		// traverse child's nodes
		for (long i = 0; i != recordNodeList->length; ++i)
		{
			MSXML2::IXMLDOMNodePtr recordNode = recordNodeList->item[i];
			if (recordNode->nodeName == (_bstr_t)"record")
			{
				MSXML2::IXMLDOMNodeListPtr dataNodeList = recordNode->childNodes;
				//name = (char *)spNode->Gettext(); 
				for (long j = 0; j != dataNodeList->length; j++)
				{
					MSXML2::IXMLDOMNodePtr dataNode = dataNodeList->item[j];
					if (dataNode->nodeName == (_bstr_t)"aankomst")
					{
						cout << endl << "aankomst:" << endl;
						aankomstdatum = dataNode->selectSingleNode("datum")->selectSingleNode("d")->Gettext() + "-";
						aankomstdatum += dataNode->selectSingleNode("datum")->selectSingleNode("m")->Gettext() + "-";
						aankomstdatum += dataNode->selectSingleNode("datum")->selectSingleNode("j")->Gettext();
						cout << aankomstdatum << endl;

						cout << dataNode->selectSingleNode("tijd")->selectSingleNode("van")->Gettext() << endl;
						cout << dataNode->selectSingleNode("tijd")->selectSingleNode("tot")->Gettext() << endl;

						cout << dataNode->selectSingleNode("soort_vervoer")->Gettext() << endl;

						cout << dataNode->selectSingleNode("bedrijf")->Gettext() << endl;

						cout << dataNode->selectSingleNode("positie")->selectSingleNode("x")->Gettext() << endl;
						cout << dataNode->selectSingleNode("positie")->selectSingleNode("y")->Gettext() << endl;
						cout << dataNode->selectSingleNode("positie")->selectSingleNode("z")->Gettext() << endl;
					}
					if (dataNode->nodeName == (_bstr_t)"eigenaar")
					{
						cout << endl << "eigenaar:" << endl;
						cout << dataNode->selectSingleNode("naam")->Gettext() << endl;
						cout << dataNode->selectSingleNode("containernr")->Gettext() << endl;
					}
					if (dataNode->nodeName == (_bstr_t)"vertrek")
					{
						cout << endl << "vertrek:" << endl;
						vertrekdatum = dataNode->selectSingleNode("datum")->selectSingleNode("d")->Gettext() + "-";
						vertrekdatum += dataNode->selectSingleNode("datum")->selectSingleNode("m")->Gettext() + "-";
						vertrekdatum += dataNode->selectSingleNode("datum")->selectSingleNode("j")->Gettext();
						cout << aankomstdatum << endl;

						cout << dataNode->selectSingleNode("tijd")->selectSingleNode("van")->Gettext() << endl;
						cout << dataNode->selectSingleNode("tijd")->selectSingleNode("tot")->Gettext() << endl;

						cout << dataNode->selectSingleNode("soort_vervoer")->Gettext() << endl;

						cout << dataNode->selectSingleNode("bedrijf")->Gettext() << endl;
					}
					if (dataNode->nodeName == (_bstr_t)"afmetingen")
					{
						cout << endl << "afmetingen:" << endl;
						cout << dataNode->selectSingleNode("l")->Gettext() << endl;
						cout << dataNode->selectSingleNode("b")->Gettext() << endl;
						cout << dataNode->selectSingleNode("h")->Gettext() << endl;
					}
					if (dataNode->nodeName == (_bstr_t)"gewicht")
					{
						cout << endl << "gewicht:" << endl;
						cout << dataNode->selectSingleNode("leeg")->Gettext() << endl;
						cout << dataNode->selectSingleNode("inhoud")->Gettext() << endl;
					}
					if (dataNode->nodeName == (_bstr_t)"inhoud")
					{
						cout << endl << "inhoud:" << endl;
						cout << dataNode->selectSingleNode("naam")->Gettext() << endl;
						cout << dataNode->selectSingleNode("soort")->Gettext() << endl;
						cout << dataNode->selectSingleNode("gevaar")->Gettext() << endl;
					}
					if (dataNode->nodeName == (_bstr_t)"ISO")
					{
						cout << endl << "ISO:" << endl;
						cout << dataNode->Gettext() << endl;
					}
					cout << recordNodeList->item[j]->nodeName;
				}
				cout << endl;
			}
		}
	}

	spRoot.Release();
	spXMLDoc.Release();
	CoUninitialize();

	return app_model;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string file; //"C:/Users/Terry/Downloads/Containing XML/XML1.xml";
	string name = "k";
	cin >> file;
	XMLlezen(file, name);
	return 0;
}




XMLReader::XMLReader()
{
}


XMLReader::~XMLReader()
{
}
