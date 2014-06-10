#ifndef netLink_H
#define netLink_H
/*
netLink class
*/
#include "netAddress.h"
#include "ifState.h"
#include <string>
using namespace std;

class netLink
{
private:
	string id;
	string name;
	//netAddress network;
	string network; //temporary until netAddress implemented
	ifState state;
	string ifSpeed;
public:
	netLink(string netLinkAddress, string netLinkMask, string netLinkID, string netLinkName, string netLinkSpeed);
	netLink();
	//netAddress getNetwork();
	string getNetwork();
	string getSpeed();
};

#endif
