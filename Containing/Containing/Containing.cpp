// Containing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;


int main()
{
	Afstandberekenaar ab;
	ab.KortsteRoute("kraan", "boot");

	/*initSockets();
	Client* client = new Client(50007);
	string name = client->conversation("Name = ");
	for (;;)
	{
		string text = client->conversation(name + "> ");
		if (text == "halt") break;
	}
	delete client;
	exitSockets();*/
}