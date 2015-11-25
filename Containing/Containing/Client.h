#pragma once
#include "stdafx.h"
#include "sockets.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <thread>

using namespace std;

class Client
{
private:
	ClientSocket socket;
	thread* th;
	bool stopped;

public:
	Client(int port);
	string conversation(string prompt);
	~Client();

};