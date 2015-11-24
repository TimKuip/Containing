// Server.cpp : Defines the entry point for the console application.
//

// Dick Bruin, 23/07/2015
// adapted for windows 09/10/2015
// Messaging Server

#include "stdafx.h"
#include "sockets.h"
#include <vector>
#include <string>
#include <iostream>
#include <thread>

using namespace std;

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

public:
	Server(int port) : socket(port)
	{
	}

	void acceptClient()
	{
		int sock = socket.accept();
		int number = getFreeClientNumber();
		clients[number].used = true;
		clients[number].socket = new ClientSocket(sock);
		clients[number].worker = newClientThread(number);
	}
private:
	int getFreeClientNumber()
	{
		int number = 0;
		while (number < clients.size() && clients[number].used) number++;
		if (number == clients.size())
			clients.push_back(Client());
		else
		{
			clients[number].worker->join();
			delete clients[number].worker;
		}
		return number;
	}

	thread* newClientThread(int number)
	{
		return new thread([number, this]()
		{
			string name = this->conversation(number, "", " has made a connection\n");
			this->clients[number].socket->write("Connected to server.\nPlease enter a text (halt = stop the program)\n");
			for (;;)
			{
				string input = this->conversation(number, name + " says ", "\n");
				if (input == "halt") break;
			}
			delete this->clients[number].socket;
			this->clients[number].used = false;
		});
	}

	string conversation(int number, string prompt1, string prompt2)
	{
		string input = clients[number].socket->read();
		string text = prompt1 + input + prompt2;
		cout << text; cout.flush();
		for (int k = 0; k<clients.size(); k++)
			if (k != number && clients[k].used)
				clients[k].socket->write(text);
		return input;
	}
};

int main()
{
	cout << "Accepting clients ...\n";
	initSockets();
	Server server(50007);
	for (;;)
	{
		server.acceptClient();
	}
	exitSockets();
}

