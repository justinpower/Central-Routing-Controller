/*
Network (IP) address class
*/

using namespace std;

class IPAddress
{
private:
	int Octets[4];
	bool mask;
public:
	IPAddress(bool mask);
	string addressToString(netAddress address);
	IPAddress stringToAddress(string address);
	bool setAddress(string address);

};