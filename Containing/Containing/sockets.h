// Dick Bruin, 19/07/2015
// adapted for windows 09/10/2015
// Messaging sockets

#ifndef SOCKETS_H
#define SOCKETS_H

#include <string>

void initSockets();
void exitSockets();

class ClientSocket
{
private:
	int sock;
public:
	ClientSocket(std::string ip, int port);
	ClientSocket(int sock);
	~ClientSocket();
	std::string read();
	void write(std::string s);
};

class ServerSocket
{
private:
	int sock;
public:
	ServerSocket(int port);
	~ServerSocket();
	int accept(); // for use in ClientSocket(int sock)
};

class sockets
{
public:
	sockets();
	~sockets();
};

#endif
