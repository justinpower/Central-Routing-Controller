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
	string addressToString(netAddress address);
	IPAddress stringToAddress(string address);
	bool setAddress(string address);

};