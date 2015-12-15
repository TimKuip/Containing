// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#import <msxml6.dll>
using namespace MSXML2;
#include <vector>
#include <string>
#include <iostream>
#include "Container.h"
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
	vector<string> xx;

	CoInitialize(NULL);

	string aankomstDatum;
	string aankomstTijdVan;
	string aankomstTijdTot;
	string aankomstVervoer;
	string aankomstBedrijf;
	string x;
	string y;
	string z;
	string naam;
	string containerNr;
	string vertrekDatum;
	string vertrekTijdVan;
	string vertrekTijdTot;
	string vertrekVervoer;
	string vertrekBedrijf;
	string lengte;
	string breedte;
	string hoogte;
	string gewichtLeeg;
	string gewicht;
	string inhoudNaam;
	string inhoudSoort;
	string gevaar;
	string iso;
	bool error;
	vector<Container*>containers;

	MSXML2::IXMLDOMDocumentPtr spXMLDoc;
	MSXML2::IXMLDOMElementPtr spRoot;
	MSXML2::IXMLDOMNodeListPtr recordNodeList;
	MSXML2::IXMLDOMNodeListPtr mainNodeList;
	MSXML2::IXMLDOMNodeListPtr dataNodeList;
	MSXML2::IXMLDOMNodeListPtr dataNodeList2;
	MSXML2::IXMLDOMNodePtr recordNode;
	MSXML2::IXMLDOMNodePtr mainNode;
	MSXML2::IXMLDOMNodePtr dataNode;
	MSXML2::IXMLDOMNodePtr dataNode2;

	spXMLDoc.CreateInstance(__uuidof(MSXML2::DOMDocument60));
	spXMLDoc->load(file.c_str());
	spRoot = spXMLDoc->documentElement;
	if (spRoot == NULL)
	{
		cout << "no rootnode found";
	}
	else if (spRoot->nodeName == (_bstr_t)"recordset")
	{
		recordNodeList = spRoot->childNodes;
		// traverse child's nodes
		for (long a = 0; a != recordNodeList->length; ++a)
		{
			error = false;
			recordNode = recordNodeList->item[a];
			if (recordNode->nodeName == (_bstr_t)"record")
			{
				mainNodeList = recordNode->childNodes;
				for (int b = 0; b != mainNodeList->length; b++)
				{
					if (error == true)
					{
						break;
					}
					mainNode = mainNodeList->item[b];
					if (mainNode->nodeName == (_bstr_t)"aankomst")
					{
						dataNodeList = mainNode->childNodes;
						for (int c = 0; c != dataNodeList->length; c++)
						{
							if (error == true)
							{
								break;
							}
							dataNode = dataNodeList->item[c];
							if (dataNode->nodeName == (_bstr_t)"datum")
							{
								dataNodeList2 = dataNode->childNodes;
								for (int d = 0; d != dataNodeList2->length; d++)
								{
									if (error == true)
									{
										break;
									}
									dataNode2 = dataNodeList2->item[d];
									if (dataNode2->nodeName == (_bstr_t)"d")
									{
										aankomstDatum = dataNode2->Gettext() + "-";
									}
									else if (dataNode2->nodeName == (_bstr_t)"m")
									{
										aankomstDatum += dataNode2->Gettext() + "-";
									}
									else if (dataNode2->nodeName == (_bstr_t)"j")
									{
										aankomstDatum += dataNode2->Gettext();
									}
									else
									{
										error = true;
									}
								}
							}
							else if (dataNode->nodeName == (_bstr_t)"tijd")
							{
								dataNodeList2 = dataNode->childNodes;
								for (int c = 0; c != dataNodeList2->length; c++)
								{
									if (error == true)
									{
										break;
									}
									dataNode2 = dataNodeList2->item[c];
									if (dataNode2->nodeName == (_bstr_t)"van")
									{
										aankomstTijdVan = dataNode2->Gettext();
									}
									else if (dataNode2->nodeName == (_bstr_t)"tot")
									{
										aankomstTijdTot = dataNode2->Gettext();
									}
									else
									{
										error = true;
									}
								}
							}
							else if (dataNode->nodeName == (_bstr_t)"soort_vervoer")
							{
								aankomstVervoer = dataNode->Gettext();
							}
							else if (dataNode->nodeName == (_bstr_t)"bedrijf")
							{
								aankomstBedrijf = dataNode->Gettext();
							}
							else if (dataNode->nodeName == (_bstr_t)"positie")
							{
								dataNodeList2 = dataNode->childNodes;
								for (int c = 0; c != dataNodeList2->length; c++)
								{
									if (error == true)
									{
										break;
									}
									dataNode2 = dataNodeList2->item[c];
									if (dataNode2->nodeName == (_bstr_t)"x")
									{
										x = dataNode2->Gettext();
									}
									else if (dataNode2->nodeName == (_bstr_t)"y")
									{
										y = dataNode2->Gettext();
									}
									else if (dataNode2->nodeName == (_bstr_t)"z")
									{
										z = dataNode2->Gettext();
									}
									else
									{

										error = true;
									}
								}
							}
						}
					}
					else if (mainNode->nodeName == (_bstr_t)"eigenaar")
					{
						dataNodeList2 = mainNode->childNodes;
						for (int c = 0; c != dataNodeList2->length; c++)
						{
							if (error == true)
							{
								break;
							}
							dataNode2 = dataNodeList2->item[c];
							if (dataNode2->nodeName == (_bstr_t)"naam")
							{
								naam = dataNode2->Gettext();
							}
							else if (dataNode2->nodeName == (_bstr_t)"containernr")
							{
								containerNr = dataNode2->Gettext();
							}
							else
							{
								error = true;
							}
						}
					}
					else if (mainNode->nodeName == (_bstr_t)"vertrek")
					{
						dataNodeList = mainNode->childNodes;
						for (int c = 0; c != dataNodeList->length; c++)
						{
							if (error == true)
							{
								break;
							}
							dataNode = dataNodeList->item[c];
							if (dataNode->nodeName == (_bstr_t)"datum")
							{
								dataNodeList2 = dataNode->childNodes;
								for (int d = 0; d != dataNodeList2->length; d++)
								{
									if (error == true)
									{
										break;
									}
									dataNode2 = dataNodeList2->item[d];
									if (dataNode2->nodeName == (_bstr_t)"d")
									{
										vertrekDatum = dataNode2->Gettext() + "-";
									}
									else if (dataNode2->nodeName == (_bstr_t)"m")
									{
										vertrekDatum += dataNode2->Gettext() + "-";
									}
									else if (dataNode2->nodeName == (_bstr_t)"j")
									{
										vertrekDatum += dataNode2->Gettext();
									}
									else
									{
										error = true;
									}
								}
							}
							else if (dataNode->nodeName == (_bstr_t)"tijd")
							{
								dataNodeList2 = dataNode->childNodes;
								for (int c = 0; c != dataNodeList2->length; c++)
								{
									if (error == true)
									{
										break;
									}
									dataNode2 = dataNodeList2->item[c];
									if (dataNode2->nodeName == (_bstr_t)"van")
									{
										vertrekTijdVan = dataNode2->Gettext();
									}
									else if (dataNode2->nodeName == (_bstr_t)"tot")
									{
										vertrekTijdTot = dataNode2->Gettext();
									}
									else
									{
										error = true;
									}
								}
							}
							else if (dataNode->nodeName == (_bstr_t)"soort_vervoer")
							{
								vertrekVervoer = dataNode->Gettext();
							}
							else if (dataNode->nodeName == (_bstr_t)"bedrijf")
							{
								vertrekBedrijf = dataNode->Gettext();
							}
							else
							{
								error = true;
							}
						}
					}
					else if (mainNode->nodeName == (_bstr_t)"afmetingen")
					{
						dataNodeList = mainNode->childNodes;
						for (int c = 0; c != dataNodeList->length; c++)
						{
							if (error == true)
							{
								break;
							}
							dataNode = dataNodeList->item[c];
							if (dataNode->nodeName == (_bstr_t)"l")
							{
								lengte = dataNode->Gettext();
							}
							else if (dataNode->nodeName == (_bstr_t)"b")
							{
								breedte = dataNode->Gettext();
							}
							else if (dataNode->nodeName == (_bstr_t)"h")
							{
								hoogte = dataNode->Gettext();
							}
							else
							{
								error = true;
							}
						}
					}
					else if (mainNode->nodeName == (_bstr_t)"gewicht")
					{
						dataNodeList = mainNode->childNodes;
						for (int c = 0; c != dataNodeList->length; c++)
						{
							if (error == true)
							{
								break;
							}
							dataNode = dataNodeList->item[c];
							if (dataNode->nodeName == (_bstr_t)"leeg")
							{
								gewichtLeeg = dataNode->Gettext();
							}
							else if (dataNode->nodeName == (_bstr_t)"inhoud")
							{
								gewicht = dataNode->Gettext();
							}
							else
							{
								error = true;
							}
						}
					}
					else if (mainNode->nodeName == (_bstr_t)"inhoud")
					{
						dataNodeList = mainNode->childNodes;
						for (int c = 0; c != dataNodeList->length; c++)
						{
							if (error == true)
							{
								break;
							}
							dataNode = dataNodeList->item[c];
							if (dataNode->nodeName == (_bstr_t)"naam")
							{
								inhoudNaam = dataNode->Gettext();
							}
							else if (dataNode->nodeName == (_bstr_t)"soort")
							{
								inhoudSoort = dataNode->Gettext();
							}
							else if (dataNode->nodeName == (_bstr_t)"gevaar")
							{
								gevaar = dataNode->Gettext();
							}
							else
							{
								error = true;
							}
						}
					}
					else if (mainNode->nodeName == (_bstr_t)"ISO")
					{
						iso = mainNode->Gettext();
					}
					else
					{
						error = true;
					}
				}
				if (error == false)
				{
					//data opslaan
					Container* container = new Container(aankomstDatum, aankomstTijdVan, aankomstTijdTot, aankomstVervoer, aankomstBedrijf, x, y, z, naam, containerNr, vertrekDatum, vertrekTijdVan, vertrekTijdTot, vertrekVervoer, vertrekBedrijf, lengte, breedte, hoogte, gewichtLeeg, gewicht, inhoudNaam, inhoudSoort, gevaar, iso);
					containers.push_back(container);

					//cout << containers[a]->ContainerNr << endl;


				}
			}
			else
			{
				cout << "invalid record";
			}
		}
		spRoot.Release();
		cout << containers[0]->ContainerNr << endl;
	}
	else
	{
		cout << "no recordset found";
		spRoot.Release();
	}

	spXMLDoc.Release();
	CoUninitialize();

	return xx;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string file = "C:/Users/Terry/Downloads/Containing XML/xml7.xml";
	string name = "x";
	XMLlezen(file, name);

	cin >> name;
	return 0;
}


