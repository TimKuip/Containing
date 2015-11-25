#pragma once
#include <string>
#include <vector>

class Client
{
private:
	ClientSocket socket;
	thread* worker;
	bool used;

public:
	Server(int port);
	socket(port);
	void acceptClient();
	


};