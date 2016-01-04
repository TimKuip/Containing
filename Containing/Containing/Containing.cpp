// Containing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "sockets.h"
#include <vector>
#include <string>
#include <algorithm>
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
	XMLlezen xmllezer;
	vector<Container> containers;
	vector<string> filenames;
	filenames.push_back("C:/Users/Albert/Documents/GitHub/Containing/Containing/Containing/XML/xml1.xml");
	filenames.push_back("C:/Users/Albert/Documents/GitHub/Containing/Containing/Containing/XML/xml2.xml");
	filenames.push_back("C:/Users/Albert/Documents/GitHub/Containing/Containing/Containing/XML/xml3.xml");
	filenames.push_back("C:/Users/Albert/Documents/GitHub/Containing/Containing/Containing/XML/xml4.xml");
	filenames.push_back("C:/Users/Albert/Documents/GitHub/Containing/Containing/Containing/XML/xml5.xml");
	filenames.push_back("C:/Users/Albert/Documents/GitHub/Containing/Containing/Containing/XML/xml6.xml");
	filenames.push_back("C:/Users/Albert/Documents/GitHub/Containing/Containing/Containing/XML/xml7.xml");
	for(string s: filenames)
	{
		containers = xmllezer.load_xml(s);
	}
	sort(containers.begin(), containers.end());
	
	cout << "Accepting clients ...\n";
	initSockets();
	ServerSocket server(50007);
	int nr = server.accept();
	ClientSocket socket(nr);
	string s = socket.read();
	cout << s << endl;
	//toegevoegt
	for (;;)
	{
		string command = "";
		for (Container c : containers)
		{
			string aankomstvervoer = c.GetAankomstVervoer;
			if (aankomstvervoer == "vrachtwagen")
			{
				command = "newLoadedVrachtwagenToDepot";
			}
			command.erase(remove_if(command.begin(), command.end(), isspace), command.end());
			socket.read();
			socket.write(command);
		}
	}
	char ch;
	cin >> ch;
	exitSockets();
}
