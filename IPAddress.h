#ifndef IPADDRESS_H
#define IPADDRESS_H
/*
Network (IP) address class
*/

using namespace std;

class IPAddress
{
private:
	int Octets[4];
	bool mask; //indicates whether or not the address is a mask
public:
	IPAddress();
	IPAddress(string address, bool mask);
	string addressToString(IPAddress address);
	IPAddress stringToAddress(string address);
	bool setAddress(string address);

};

#endif
