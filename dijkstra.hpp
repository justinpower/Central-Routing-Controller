#include <iostream>
#include <string>
using namespace std;

vector< vector<string> > getLocalNets(const vector<router> & routers)
{
	vector< vector<string> > localNets;
	
	for (int i=0; i < routers.size(); i++)
	{
		vector<link> links = routers[i].getLinks();
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
vector< vector<string> > buildMapKey(const vector< vector<string> > & localNets, const vector<router> & routers)
{
	vector< vector<string> > mapKey;
	vector<string> row;
	for (int i=0; i<routers.size(); i++)
	{
		row.push_back(routers[i].getName());
		mapKey.push_back(row);
	}
	vector<string> column = row;
	for (int i=0; i<localNets.size(); i++)
	{
		column.push_back(localNets[i][0]);
		mapKey.push_back(column);
	}
	return mapKey;
}

	
void findSharedNets(vector< vector<string> > & localNets)
{
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
				localNets.push_back(row);
			}
		}
	}
}

vector< vector<int> > buildAdjacency(const vector< vector<string> > & localNets, const vector< vector<string> > & mapKey)
{
	vector< vector<int> > adjMatrix;
	//initialize the matrix
	vector<int> initRow;
	vector<int> initColumn;
	for (int i=0; i<mapKey[0].size(); i++)
	{
		initRow.push_back(-1);
	}
	adjMatrix.push_back(initRow);
	for (int i=0; i<mapKey[0].size(); i++)
	{
		initColumn.push_back(-1);
	}
	adjMatrix.push_back(initColumn);
	//initialization complete
	
	for (int i=0; i<localNets.size(); i++)
	{
		int currCost = atoi(localNets[i][2].c_str());
		int rowIndex = findIndex(mapKey, localNets[i][1], 0); //0 signifies that we are searching rows (router list), not columns (routers and networks)
		int clmnIndex = findIndex(mapKey, localNets[i][0], 1);
		if (adjMatrix[rowIndex][clmnIndex] == -1 || currCost < adjMatrix[rowIndex][clmnIndex])
		{
			adjMatrix[rowIndex][clmnIndex] = currCost;
		}
	}
	
	return adjMatrix;
}

int findIndex(const vector< vector<string> > & matrix, string key, int row)
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