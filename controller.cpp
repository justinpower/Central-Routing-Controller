#include <iostream>
#include <vector>
#include <string>
#include "router.cpp"
#include "IPAddress.cpp"
#include "ifState.cpp"
#include "link.cpp"
#include "routeTable.cpp"
#include "snmp.cpp"
#include "netAddress.cpp"

using namespace std;

int main()
{
	vector<router> network;
	router routerA;
	routerA.initialize("192.168.1.1", true, "A.txt");
	network.push_back(routerA);
	
	router routerB;
	routerB.initialize("192.168.1.2", true, "B.txt");
	network.push_back(routerB);
	
	router routerC;
	routerC.initialize("192.168.2.2", true, "C.txt");
	network.push_back(routerC);
	
	
	routerA.printIntIps();
	routerA.printIntIds();
	
}
