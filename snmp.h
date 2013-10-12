#ifndef SNMP_H
#define SNMP_H
/*
SNMP action class
*/
#include <vector>
using namespace std;

class snmp
{
private:
string exec(char* cmd);

public:
	snmp();
	vector<string> getAddresses(string target, string community, bool id);
	vector<string> getMasks(string target, string community);
	vector<string> getInterfaces(string target, string community);
	vector<string> getSpeeds(string target, string community);
	
};

#endif
