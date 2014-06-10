#ifndef netLink_CPP
#define netLink_CPP

#include "netAddress.h"
#include "ifState.h"
#include <string>
using namespace std;

netLink::netLink()
{

}

netLink::netLink(string netLinkAddress, string netLinkMask, string netLinkID, string netLinkName, string netLinkSpeed)
{
	network = netLinkAddress + "/" + netLinkMask;
	id = netLinkID;
	name = netLinkName;
	ifSpeed = netLinkSpeed;
}

/*
netAddress netLink::getNetwork()
{

}
*/

string netLink::getNetwork()
{
	return network;
}

string netLink::getSpeed()
{
	return ifSpeed;
}

#endif
