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

#endif
