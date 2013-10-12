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
	router routerA;
	routerA.initialize("192.168.1.6");
	routerA.printIntIps();
	routerA.printIntIds();
	
}
