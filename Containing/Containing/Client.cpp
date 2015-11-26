// Client.cpp : Defines the entry point for the console application.
//

// Dick Bruin, 23/07/2015
// adapted for windows 09/10/2015
// Messaging Client

#include "Client.h"
#include "stdafx.h"

Client::Client(int port) : socket("127.0.0.1", port)
{
	stopped = false;
	th = new thread([this]()
	{
		for (;;)
		{
			cout << endl << this->socket.read() << "> "; cout.flush();
			if (this->stopped) break;
		}
	});
}

Client::~Client()
{
	stopped = true;
	th->join();
	delete th;
}

string Client::conversation(string prompt)
{
	string text;
	for (;;)
	{
		cout << prompt; cout.flush();
		getline(cin, text);
		if (any_of(text.begin(), text.end(), [](char c) {return c != ' '; })) break;
	}
	socket.write(text);
	return text;
}



