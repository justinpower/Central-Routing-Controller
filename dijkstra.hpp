#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <iostream>
#include <string>
#include "pQueue.hpp"
#include "hop.hpp"
using namespace std;

vector< vector<string> > getLocalNets(vector<router> & routers)
{
	vector< vector<string> > localNets;
	
	for (int i=0; i < routers.size(); i++)
	{
		vector<netLink> links = routers[i].getNetLinks();
		for (int j=0; j < links.size(); j++)
		{
			vector<string> row;
			row.push_back(links[j].getNetwork());
			row.push_back(routers[i].getName());
			row.push_back(links[j].getSpeed());
			localNets.push_back(row);
		}
	}
		return localNets;
}

//This function creates a two dimensional vector of strings in which the first row of the vector contains
//a list of strings that represent the rows of the adjacency matrix (a list of routers) and the second row
//of mapKey is a list of routers and networks that represents the columns of the adjacency matrix.
//Note: This would need to be run before findSharedNets is run.
vector< vector<string> > buildMapKey(vector< vector<string> > & localNets, vector<router> & routers)
{
	vector< vector<string> > mapKey;
	vector<string> row;
	//each row of the map key is just the routers' names
	for (int i=0; i<routers.size(); i++)
	{
		row.push_back(routers[i].getName());
	}
	//set the rows to be the routers' names and start the columns to also be the routers names
	mapKey.push_back(row);
	vector<string> column = row;
	
	bool duplicate;
	for (int i=0; i<localNets.size(); i++)
	{
		duplicate = false;
		for (int j=0; j<column.size(); j++)
		{
			if (localNets[i][0] == column[j])
			{
				duplicate = true;
			}
		}
		if (!duplicate)
		{
			column.push_back(localNets[i][0]);
		}
	}
	mapKey.push_back(column);
	return mapKey;
}

	
vector< vector<string> > findSharedNets(vector< vector<string> > & localNets)
{
	vector< vector<string> > localNetsHops = localNets;
	for (int i=0; i <localNets.size(); i++)
	{
		string currNet = localNets[i][0];
		string currRouter = localNets[i][1];
		string currCost = localNets[i][2];
		for (int j=0; j < localNets.size(); j++)
		{
			if (localNets[j][0] == currNet && localNets[j][1] != currRouter)
			{
				vector<string> row;
				row.push_back(localNets[j][1]);
				row.push_back(currRouter);
				row.push_back(currCost);
				localNetsHops.push_back(row);
			}
		}
	}
	return localNetsHops;
}

int findIndex(vector< vector<string> > & matrix, string key, int row)
{
	int index;
	for (int i=0; i<matrix[row].size(); i++)
	{
		if (matrix[row][i]==key)
		{
			index = i;
			return index;
		}
	}

	return -1;
}

vector< vector<int> > buildAdjacency(vector< vector<string> > & localNetsHops, vector< vector<string> > & mapKey)
{
	vector< vector<int> > adjMatrix;
	//initialize the matrix
	vector<int> initRow;
	vector<int> initColumn;
	for (int i=0; i<mapKey[1].size(); i++)
	{
		initRow.push_back(-1);
	}
	for (int i=0; i<mapKey[0].size(); i++)
	{
		adjMatrix.push_back(initRow);
		initColumn.push_back(-1);
	}
//	for (int i=0; i<mapKey[1].size(); i++)
//	{
//		adjMatrix.push_back(initColumn);
//	}
	//initialization complete
	
	for (int i=0; i<localNetsHops.size(); i++)
	{
		int currCost = atoi(localNetsHops[i][2].c_str());
		int rowIndex = findIndex(mapKey, localNetsHops[i][1], 0); //0 signifies that we are searching rows (router list), not columns (routers and networks)
		int clmnIndex = findIndex(mapKey, localNetsHops[i][0], 1);
		if (adjMatrix[rowIndex][clmnIndex] == -1 || currCost < adjMatrix[rowIndex][clmnIndex])
		{
			adjMatrix[rowIndex][clmnIndex] = currCost;
		}
	}
	
	//set cost to 0 where hops are connected to themselves
	for (int i=0; i<mapKey[0].size(); i++)
	{
		adjMatrix[i][i] = 0;
	}
	
	return adjMatrix;
}

vector< vector<string> > buildRoutes(vector< vector<int> > adjMatrix, int source)
{
	int adjMatrixRows = adjMatrix.size();
	cout << "adjMatrixRows is " << adjMatrixRows << endl;
	int size = adjMatrix[1].size();
	pQueue hops;
	pQueue known;
	hops.initialize(size);
	hops.setSource(source);
	for (int i=0; i<size; i++)
	{
		hop parent = hops.deleteMin();
		//size--; //because the size of the pqueue is shrinking?
		known.insert(parent);
		cout << "parent.getName() is " << parent.getName() << endl;
		if (parent.getName() < adjMatrixRows)	//if the name of the parent is larger than the number of rows, then it must be a network not a router
		{
			for (int j=0; j<size; j++)
			{
				if (adjMatrix[parent.getName()][j] != -1) //check if the parent has a path to the node
				{
					cout << "setting fringeDist to " << j << " to " << parent.getDistance() << " + " << adjMatrix[parent.getName()][j] << endl;
					int fringeDist = (parent.getDistance() + adjMatrix[parent.getName()][j]);
					if (fringeDist < hops.getHopDist(j) || hops.getHopDist(j) == -1)
					{
						cout << "updating hop " << j << " with distance " << fringeDist << endl;
						hops.updateHop(j, parent.getName(), fringeDist);
					}
				}
			}
		}
	}
	known.print();
	vector< vector<string> > routes;
	return routes;
}

#endif
