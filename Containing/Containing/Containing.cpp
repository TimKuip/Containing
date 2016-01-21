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
	
	//in te lezen bestanden in een array zetten
	vector<string> filenames;
	filenames.push_back("C:/Users/Terry/Downloads/Containing XML/xml1.xml");
	filenames.push_back("C:/Users/Terry/Downloads/Containing XML/xml2.xml");
	filenames.push_back("C:/Users/Terry/Downloads/Containing XML/xml3.xml");
	filenames.push_back("C:/Users/Terry/Downloads/Containing XML/xml4.xml");
	/*filenames.push_back("C:/Users/Terry/Downloads/Containing XML/xml5.xml");
	filenames.push_back("C:/Users/Terry/Downloads/Containing XML/xml6.xml");
	filenames.push_back("C:/Users/Terry/Downloads/Containing XML/xml7.xml");*/

	//XML lezen
	containers = xmllezer.load_xml(filenames);
	sort(containers.begin(), containers.end());

	int vrachtauto = 0;
	int zeeschip = 0;
	int binnenschip = 0;
	int trein = 0;
	int opslag = 0;

	//double actueleTijd = 0.00;
	//string actueleDag = "00-00-00";

	//containers tellen op verschillende plaatsen
	for (Container container : containers)
	{
		if (/*actueleTijd < container.GetAankomstTijdTot() && actueleDag <= container.GetAankomstDatum() && */container.GetAankomstVervoer() == "vrachtauto")
		{
			vrachtauto++;
		}
		/*else if (actueleTijd > container.GetVertrekTijdVan() && actueleDag >= container.GetVertrekDatum() && container.GetVertrekVervoer() == "vrachtauto")
		{
		vrachtauto++;
		}*/
		else if (/*actueleTijd < container.GetAankomstTijdTot() && actueleDag <= container.GetAankomstDatum() &&*/ container.GetAankomstVervoer() == "trein")
		{
			trein++;
		}
		/*else if (actueleTijd > container.GetVertrekTijdVan() && actueleDag >= container.GetVertrekDatum() && container.GetVertrekVervoer() == "trein")
		{
		trein++;
		}*/
		else if (/*actueleTijd < container.GetAankomstTijdTot() && actueleDag <= container.GetAankomstDatum() &&*/ container.GetAankomstVervoer() == "zeeschip")
		{
			zeeschip++;
		}
		/*else if (actueleTijd > container.GetVertrekTijdVan() && actueleDag >= container.GetVertrekDatum() && container.GetVertrekVervoer() == "zeeschip")
		{
		zeeschip++;
		}*/
		else if (/*actueleTijd < container.GetAankomstTijdTot() && actueleDag <= container.GetAankomstDatum() &&*/ container.GetAankomstVervoer() == "binnenschip")
		{
			binnenschip++;
		}
		/*else if (actueleTijd > container.GetVertrekTijdVan() && actueleDag >= container.GetVertrekDatum() && container.GetVertrekVervoer() == "binnenschip")
		{
		binnenschip++;
		}*/
		else
		{
			opslag++;
		}
	}

	cout << "Accepting clients ...\n";
	initSockets();
	ServerSocket server(50007);
	bool  running = true;
	while (running)
	{
		//wachten op verbinding
		int nr = server.accept();
		ClientSocket socket(nr);
		string s = socket.read();
		cout << s << endl;
		
		//aantallen containers naar app sturen
		if (s == "getdata")
		{
			socket.write(to_string(vrachtauto));
			cout << vrachtauto << endl;
			socket.read();
			socket.write(to_string(trein));
			cout << zeeschip << endl;
			socket.read();
			socket.write(to_string(zeeschip));
			cout << trein << endl;
			socket.read();
			socket.write(to_string(binnenschip));
			cout << binnenschip << endl;
			socket.read();
			socket.write(to_string(opslag));
			cout << opslag << endl;
		}
		else if (s == "simulatie")
		{
			for (;;)
			{
				string command = "";
				for (Container c : containers)
				{
					string aankomstvervoer = c.GetAankomstVervoer();
					if (aankomstvervoer == "vrachtwagen")
					{
						command = "newLoadedVrachtwagenToDepot";
					}
					command.erase(remove_if(command.begin(), command.end(), isspace), command.end());
					socket.read();
					socket.write(command);
				}
			}
		}
	}

	char ch;
	cin >> ch;
	exitSockets();
}
