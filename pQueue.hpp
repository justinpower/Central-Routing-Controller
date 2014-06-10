#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "hop.hpp"
using namespace std;

	bool hopcmd(const hop& i, const hop& j)
	{
		//int a = i.getDistance();
		//int b = j.getDistance();
		// if (i.getDistance() == -1)
		// {
			// return true;
		// }
		// if (j.getDistance() == -1)
		// {
			// return false;
		// }
		return (i.getDistance() < j.getDistance());
	}

class pQueue
{
private:
	vector<hop> queue;
	// static bool hopcmd(const hop& i, const hop& j)
	// {
		// //int a = i.getDistance();
		// //int b = j.getDistance();
		// if (i.getDistance() == -1)
		// {
			// return true;
		// }
		// else if (j.getDistance() == -1)
		// {
			// return false;
		// }
		// else
		// {
			// return (j.getDistance() < i.getDistance());
		// }
	// }
	void qSort()
	{
		hop testHop = *queue.begin();
		cout << "test.getDistance is " << testHop.getDistance() << endl;
		//sort(queue.begin(), queue.end(), myobject);
		//sort(queue.begin(), queue.end(), hopCompare());
		sort(queue.begin(), queue.end(), hopcmd);
	}
public:
	pQueue() {};
	hop deleteMin() //pop the top
	{
		
		hop min = queue.back();
		queue.pop_back();
		return min;
	}
	void insert(hop newHop)
	{
		queue.push_back(newHop);
	}
	void initialize(int size) //create all the hops
	{
		for (int i=0; i<size; i++)
		{
			queue.push_back(hop(i));
		}
	}
	void setSource(int source)
	{
		for (int i=0; i<queue.size(); i++)
		{
			cout << queue[i].getName() << endl;
			if (queue[i].getName() == source)
			{
				queue[i].setDistance(0);
				break;
			}
		}
		qSort();
	}
	void updateHop(int hop, int parent, int dist)
	{
		for (int i=0; i<queue.size(); i++)
		{
			if (queue[i].getName() == hop)
			{
				queue[i].setParent(parent);
				queue[i].setDistance(dist);
			}
		}
		qSort();
	}
	int getHopDist(int name)
	{
		int hopDist = -1;
		for (int i=0; i<queue.size(); i++)
		{
			if (queue[i].getName() == name)
			{
				hopDist = queue[i].getDistance();
			}
		}
		return hopDist;
	}
	void print()
	{
		for (int i=0; i<queue.size(); i++)
		{
			cout << queue[i].getName() << "d=" << queue[i].getDistance() << " | |";
		}
		cout << endl;
	}
};

#endif //PQUEUE_H