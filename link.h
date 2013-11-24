#ifndef LINK_H
#define LINK_H
/*
Link class
*/
#include "netAddress.h"
#include "ifState.h"
#include <string>
using namespace std;

class link
{
private:
	int id;
	string name;
	//netAddress network;
	string network; //temporary until netAddress implemented
	ifState state;
	string ifSpeed;
public:
	link(string linkAddress, string linkMask, string linkID, string linkName, string linkSpeed);
	//netAddress getNetwork();
	string getNetwork();
	string getSpeed();
};

#endif
