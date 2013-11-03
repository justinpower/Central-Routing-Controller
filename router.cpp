#ifndef ROUTER_CPP
#define ROUTER_CPP
#include "router.h"
#include <string>
#include <vector>
#include "link.h"
#include "routeTable.h"
#include "snmp.h"

using namespace std;

router::router()
{

}
bool router::initialize(string addr)
{
	address = addr;
	intIps = agent.getAddresses(address, "csusm!", false);
	intIds = agent.getAddresses(address, "csusm!", true);
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
