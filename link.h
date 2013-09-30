/*
Link class
*/
#include <"netAddress.h">
#include <"ifState.h">
#include <string>
using namespace std;

class link
{
private:
	int id;
	string name;
	netAddress network;
	ifState state;
	int ifSpeed;
	
	
	
};