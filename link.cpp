#ifndef LINK_CPP
#define LINK_CPP

#include "netAddress.h"
#include "ifState.h"
#include <string>
using namespace std;
link::link(string linkAddress, string linkMask, string linkID, string linkName, string linkSpeed)
{
	network = linkAddress + "/" linkMask;
	id = linkId;
	name = linkName;
	ifSpeed = linkSpeed;
}

/*
netAddress link::getNetwork()
{

}
*/

string link::getNetwork()
{
	return network;
}

string link::getSpeed()
{
	return ifSpeed;
}

#endif
