#include "stdafx.h"
#include <string>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "sockets.h"

#pragma comment(lib,"ws2_32.lib")

using namespace std;

#define bufsize 4096

void initSockets()
{
	WSADATA WsaDat;
	WSAStartup(MAKEWORD(2, 2), &WsaDat);
}

void exitSockets()
{
	WSACleanup();
}

ClientSocket::ClientSocket(string ip, int port)
{
	sockaddr_in sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);
	inet_pton(AF_INET, ip.c_str(), &sa.sin_addr);

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	connect(sock, (const sockaddr *)&sa, sizeof(sa));
}

ClientSocket::ClientSocket(int sock)
{
	this->sock = sock;
}

ClientSocket::~ClientSocket()
{
	shutdown(sock, SD_SEND);
	closesocket(sock);
}

string ClientSocket::read()
{
	char buffer[bufsize];
	int count = recv(sock, buffer, bufsize - 1, 0);
	if (count > 0 && buffer[count - 1] == '\n') count--;
	buffer[count] = '\0';
	return string(buffer);
}

void ClientSocket::write(string s)
{
	int count = s.size();
	if (count > bufsize - 1) throw runtime_error("ClientSocket::write - argument too large");
	char buffer[bufsize];
	strcpy_s(buffer, s.c_str());
	buffer[count++] = '\n';
	buffer[count++] = '\0';
	send(sock, buffer, count, 0);
}

ServerSocket::ServerSocket(int port)
{
	sockaddr_in sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);

	char yes = 1;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	bind(sock, (const sockaddr*)&sa, sizeof(sa));
	listen(sock, 1);
}

ServerSocket::~ServerSocket()
{
	shutdown(sock, SD_SEND);
	closesocket(sock);
}

int ServerSocket::accept()
{
	return ::accept(sock, NULL, NULL);
}
