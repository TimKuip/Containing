#pragma once
#include <string>
#include <vector>
#include "stdafx.h"
#include "sockets.h"

class Server
{
private:
	struct Client 
	{
		bool          used;
		ClientSocket* socket;
		thread*       worker;
	};
	vector<Client> clients;
	ServerSocket socket;
	int getFreeClientNumber();
	thread* newClientThread(int number);
	string conversation(int number, string prompt1, string prompt2);

public:
	Server(int port);
	void acceptClient();
};

