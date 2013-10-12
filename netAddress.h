#ifndef NETADDRESS_H
#define NETADDRESS_H
/*
Network (IP) address class
*/
#include "IPAddress.h"

using namespace std;

class netAddress
{
private:
	IPAddress address;
	IPAddress mask;
public:
	netAddress();
	netAddress(string address, string mask);

};

#endif
