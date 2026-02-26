#pragma once
#include <iostream>
#include <string>
using namespace std;



class interfaceCommunication
{
public:
	virtual void sendEmail(string title, string body) = 0;
	virtual void sendFax(string title, string body) = 0;
};

