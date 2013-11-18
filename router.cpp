#ifndef ROUTER_CPP
#define ROUTER_CPP
#include "router.h"
#include <string>
#include <vector>
#include "link.h"
#include "routeTable.h"
#include "snmp.h"
#include <fstream>

using namespace std;

router::router()
{

}
bool router::initialize(string addr, bool test, string file)
{
	if (!test)
	{
		address = addr;
		intIps = agent.getAddresses(address, "csusm!", false); //get the IPs
		intIds = agent.getAddresses(address, "csusm!", true); //get the interface IDs
		return true;
	}
	else
	{
		return loadFile(file);
	}
}
bool router::loadFile(string file)
{
	ifstream infile(file);
	string tempAddress, tempMask, tempIntID, tempIntName, tempSpeed;
	while(infile >> tempAddress >> tempMask >> tempIntID >> tempIntName >> tempSpeed)
	{
		links.push_back(new link(tempAddress, tempMask, tempIntID, tempIntName, tempSpeed));
	}
}
bool router::setAddress(string addr)
{
	address = addr;
	return true;
}
bool router::addLink(link newLink)
{
	return true;
}
bool router::setRouteTable(routeTable table)
{
	return true;
}
bool router::setIntIps(vector<string> ips)
{
	intIps = ips;
	return true;
}
bool router::setIntIds(vector<string> ids)
{
	intIds = ids;
	return true;
}
vector<link> router::getLinks()
{
	return links;
}
string router::getAddress()
{
	return address;
}
string router::getName()
{
	return name;
}
void router::printIntIps()
{
	for (int i=0; i<intIps.size(); i++)
	{
		cout << intIps[i] << endl;
	}
}
void router::printIntIds()
{
	for (int i=0; i<intIds.size(); i++)
	{
		cout << intIds[i] << endl;
	}
}

vector<netAddress> router::getLocalNets()
{
	vector<netAddress> localNets;
	for (int i=0; i<links.size(); i++)
	{
		localNets.push_back(links[i].getConnectedNet());
	}
	return localNets;
}

#endif
