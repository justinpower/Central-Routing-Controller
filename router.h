/*
Router class
*/
#include <string>
#include <vector>
#include <"link.h">
#include <"routeTable.h">
using namespace std;

class router
{
private:
	string name;
	string address;
	vector<link> links;
	routeTable routes;
public:
	router();
	bool setAddress(string addr);
	bool addLink(link newLink);
	bool setRouteTable(routeTable table);
	vector<link> getLinks();
	string getAddress();
};