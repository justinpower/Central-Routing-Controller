#ifndef ROUTER_H
#define ROUTER_H
/*
Router class
*/
#include <string>
#include <vector>
#include "netLink.h"
#include "routeTable.h"
#include "snmp.h"
#include "netAddress.h"
using namespace std;

class router
{
private:
	string name;
	string address;
	vector<netLink> netLinks;
//	routeTable routes;
	vector<string> intIds;
	vector<string> intIps;
	snmp agent;
	string vendor;
public:
	router();
	bool initialize(string rName, string addr, bool test, string file);
	bool loadFile(string file);
	bool setAddress(string addr);
	bool addNetLink(netLink newNetLink);
	bool setRouteTable(routeTable table);
	bool setIntIps(vector<string> ips);
	bool setIntIds(vector<string> ids);
	vector<netLink> getNetLinks();
	vector<string> getLocalNets();
//	vector<netAddress> getLocalNets();
	string getAddress();
	string getName();
	void printIntIps();
	void printIntIds();
};

#endif
