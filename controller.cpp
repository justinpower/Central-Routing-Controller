#include <iostream>
#include <vector>
#include <string>
#include "router.cpp"
#include "IPAddress.cpp"
#include "ifState.cpp"
#include "netLink.cpp"
#include "routeTable.cpp"
#include "snmp.cpp"
#include "netAddress.cpp"
#include "dijkstra.hpp"

using namespace std;

int main()
{
	vector<router> network;
	router routerA;
	routerA.initialize("A", "192.168.1.1", true, "A.txt");
	network.push_back(routerA);
	
	router routerB;
	routerB.initialize("B", "192.168.1.2", true, "B.txt");
	network.push_back(routerB);
	
	router routerC;
	routerC.initialize("C", "192.168.2.2", true, "C.txt");
	network.push_back(routerC);
	
	
	//routerA.printIntIps();
	//routerA.printIntIds();
	
	vector< vector<string> > localNets = getLocalNets(network);
	
	cout << endl << "Local networks:" << endl;
	for (int i=0; i<localNets.size(); i++)
	{
		cout << localNets[i][0] << "\t" << localNets[i][1] << "\t" << localNets[i][2] << endl;
	}
	
	vector< vector<string> > mapKey = buildMapKey(localNets, network);
	
	cout << endl << "Map key:" << endl;
	cout << "\t";
	for (int i=0; i<mapKey[1].size(); i++)
	{
		cout << mapKey[1][i] << "\t";
	}
	cout << endl;
	for (int i=0; i<mapKey[0].size(); i++)
	{
		cout << mapKey[0][i] << "\n";
	}
	
	vector< vector<string> > localNetsHops = findSharedNets(localNets);
	
	cout << endl << "Local networks and local routers:" << endl;
	for (int i=0; i<localNetsHops.size(); i++)
	{
		cout << localNetsHops[i][0] << "\t" << localNetsHops[i][1] << "\t" << localNetsHops[i][2] << endl;
	}
	
	vector< vector<int> > adjMatrix = buildAdjacency(localNetsHops, mapKey);
	
	cout << endl << "Adjacency Matrix:" << endl;
	for (int i=0; i<adjMatrix.size(); i++)
	{
		for (int j=0; j<adjMatrix[i].size(); j++)
		{
			cout << adjMatrix[i][j] << "\t";
		}
		cout << "\n";
	}
	
	vector< vector<string> > routeTable = buildRoutes(adjMatrix, 0);
	
}

