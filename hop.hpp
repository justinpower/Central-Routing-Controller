#ifndef HOP_H
#define HOP_H

#include <iostream>
using namespace std;

class hop
{
private:
	int parent;
	int distance;
	int name;
	bool router;
public:
	hop(int newName, bool isRouter) { parent = NULL; distance = -1; name = newName; router = isRouter }
	bool isRouter() { return router; }
	void setParent(int newParent) { parent = newParent; }
	void setDistance(int newDistance) { distance = newDistance; }
	int getDistance() { return distance; }
	int getName() { return name; }
	int getParent() { return parent; }
};

#endif //HOP_H