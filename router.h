#ifndef ROUTER_H
#define ROUTER_H
/*
Router class
*/
#include <string>
#include <vector>
#include "link.h"
#include "routeTable.h"
#include "snmp.h"
using namespace std;

class router
{
private:
	string name;
	string address;
	vector<link> links;
//	routeTable routes;
	vector<string> intIds;
	vector<string> intIps;
	snmp agent;
public:
	router();
	bool initialize(string addr);
	bool setAddress(string addr);
	bool addLink(link newLink);
	bool setRouteTable(routeTable table);
	bool setIntIps(vector<string> ips);
	bool setIntIds(vector<string> ids);
	vector<link> getLinks();
	string getAddress();
	string getName();
	void printIntIps();
	void printIntIds();
};

#endif
