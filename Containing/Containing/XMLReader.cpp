// ConsoleApplication2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#import <msxml6.dll>
#include "XMLreader.h"
#include <vector>
#include <string>
#include <iostream>

#include <time.h>

using namespace MSXML2;
using namespace std;



//klasse staat nu in XMLreader.h, heb dit uitgecommend voor het geval dat het weer niet werkt zodat we snel kunnen oplossen
/*
class XMLlezen
{
public:
	vector<string>load_xml(string file, string name);

	XMLlezen(string file, string name)
	{
		load_xml(file, name);
	}
};
*/
XMLlezen::XMLlezen()
{
	
}

vector<Container> XMLlezen::load_xml(vector<string> files)
{
	string aankomstDatum = "";
	double aankomstTijdVan = 0;
	double aankomstTijdTot = 0;
	string aankomstVervoer = "";
	string aankomstBedrijf = "";
	int x = 0;
	int y = 0;
	int z = 0;
	string eigenaar = "";
	int containerNr = 0;
	string vertrekDatum = "";
	double vertrekTijdVan = 0;
	double vertrekTijdTot = 0;
	string vertrekVervoer = "";
	string vertrekBedrijf = "";
	double lengte = 0;
	double breedte = 0;
	double hoogte = 0;
	int gewichtLeeg = 0;
	int gewicht = 0;
	string inhoudNaam = "";
	string inhoudSoort = "";
	string gevaar = "";
	string iso = "";
	bool error;
	vector<Container>containers;
	string waarde;

	for (string file : files)
	{
		int containersSize = containers.size();
		CoInitialize(NULL);
		{

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
				int listLength = recordNodeList->length;
				// traverse child's nodes
				for (int a = 0; a < recordNodeList->length; a++)
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
												waarde = dataNode2->Gettext();
												aankomstTijdVan = stod(waarde);
											}
											else if (dataNode2->nodeName == (_bstr_t)"tot")
											{
												waarde = dataNode2->Gettext();
												aankomstTijdTot = stod(waarde);
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
												waarde = dataNode2->Gettext();
												x = stoi(waarde);
											}
											else if (dataNode2->nodeName == (_bstr_t)"y")
											{
												waarde = dataNode2->Gettext();
												y = stoi(waarde);
											}
											else if (dataNode2->nodeName == (_bstr_t)"z")
											{
												waarde = dataNode2->Gettext();
												z = stoi(waarde);
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
										eigenaar = dataNode2->Gettext();
									}
									else if (dataNode2->nodeName == (_bstr_t)"containernr")
									{
										waarde = dataNode2->Gettext();
										containerNr = stoi(waarde);
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
												waarde = dataNode2->Gettext();
												vertrekTijdVan = stod(waarde);
											}
											else if (dataNode2->nodeName == (_bstr_t)"tot")
											{
												waarde = dataNode2->Gettext();
												vertrekTijdTot = stod(waarde);
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
										waarde = dataNode->Gettext();
										lengte = stod(waarde);
									}
									else if (dataNode->nodeName == (_bstr_t)"b")
									{
										waarde = dataNode->Gettext();
										breedte = stod(waarde);
									}
									else if (dataNode->nodeName == (_bstr_t)"h")
									{
										waarde = dataNode->Gettext();
										hoogte = stod(waarde);
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
										waarde = dataNode->Gettext();
										gewichtLeeg = stoi(waarde);
									}
									else if (dataNode->nodeName == (_bstr_t)"inhoud")
									{
										waarde = dataNode->Gettext();
										gewicht = stoi(waarde);
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
							int index = a + containersSize;
							Container container;
							containers.push_back(container);
							containers[index].SetAankomstDatum(aankomstDatum);
							containers[index].SetAankomstTijdVan(aankomstTijdVan);
							containers[index].SetAankomstTijdTot(aankomstTijdTot);
							containers[index].SetAankomstVervoer(aankomstVervoer);
							containers[index].SetAankomstBedrijf(aankomstBedrijf);
							containers[index].SetX(x);
							containers[index].SetY(y);
							containers[index].SetZ(z);
							containers[index].SetEigenaar(eigenaar);
							containers[index].SetContainerNr(containerNr);
							containers[index].SetVertrekDatum(vertrekDatum);
							containers[index].SetVertrekTijdVan(vertrekTijdVan);
							containers[index].SetVertrekTijdTot(vertrekTijdTot);
							containers[index].SetVertrekVervoer(vertrekVervoer);
							containers[index].SetVertrekBedrijf(vertrekBedrijf);
							containers[index].SetLengte(lengte);
							containers[index].SetBreedte(breedte);
							containers[index].SetHoogte(hoogte);
							containers[index].SetGewichtLeeg(gewichtLeeg);
							containers[index].SetGewicht(gewicht);
							containers[index].SetInhoudNaam(inhoudNaam);
							containers[index].SetInhoudSoort(inhoudSoort);
							containers[index].SetGevaar(gevaar);
							containers[index].SetIso(iso);
						}
					}
					else
					{
						cout << "invalid record";
					}
				}

				spRoot.Release();
			}
			else
			{
				cout << "no recordset found";
				spRoot.Release();
			}

			spXMLDoc.Release();
		}
		CoUninitialize();
	}

	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	cout << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << endl;
	
	return containers;
}




