#include <iostream>
#include <"router.h">
#include <"IPAddress.h">
#include <"ifState.h">
#include <"link.h">
#include <"routeTable.h">
#include <"snmp.h">
#include <"netAddress.h">

using namespace std;

int main()
{
	router testRouter();
	testRouter.setAddress("192.168.1.6");
	snmp agent();
	vector<string> testRouterAdrs = agent.getAddresses(testRouter.getAddress, "csusm!", false);
	vector<string> testRouterIDs = agent.getAddresses(testRouter.getAddress, "csusm!", true);
}