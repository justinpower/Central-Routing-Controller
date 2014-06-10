#ifndef NETADDRESS_CPP
#define NETADDRESS_CPP

#include "netAddress.h"
#include <string>
#include "stringManip.hpp"

using namespace std;

netAddress::netAddress()
{

}
netAddress::netAddress(string address, string mask)
{
	slashNotation = address + "/" + mask; //evenutally need to have it actually generate slash notation?
}

string netAddress::getSlashNet()
{
	return slashNotation;
}

#endif
