/*
SNMP action class
*/

using namespace std;

class snmp
{
private:

public:
	snmp();
	string getAddresses(netAddress target);
	string getMasks(netAddress target);
	string getInterfaces(netAddress target);
	string getSpeeds(netAddress target);
	
};