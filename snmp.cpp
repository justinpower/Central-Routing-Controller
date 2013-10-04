#include <"snmp.h">
#include <iostream>
#include <string>
#include <stdio.h>
#include <"netAddress.h">
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

snmp::snmp()
{
    //constructor
}

vector<netAddress> snmp::getAddresses(string target, string community)
{
    char cmd[] = "snmpwalk -v1 -c " + community + " " + target + " 1.3.6.1.2.1.4.20.1.2";
    string walkResult = exec(cmd);
    vector<string> outputLines;
    split(outputLines, walkResult, is_any_of( "\n" ));
}

vector<netAddress> snmp::getMasks(string target, string community)
{

}

vector<string> snmp::getInterfaces(string target, string community)
{

}

vector<string> snmp::getSpeeds(string target, string community)

}

string snmp::exec(char* cmd) 
{
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    string result = "";
    while(!feof(pipe)) 
    {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}