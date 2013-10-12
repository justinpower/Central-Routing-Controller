#ifndef SNMP_CPP
#define SNMP_CPP
#include "snmp.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include "netAddress.h"
#include <vector>
#include <string.h>
#include "stringManip.hpp"

using namespace std;

snmp::snmp()
{
    //constructor
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

vector<string> snmp::getAddresses(string target, string community, bool id)
{
	//fIndex indicates which field of the output to return, the ip address or the interface ID
	int fIndex = 0;	//the default is the ip address
	if (id)
	{
		fIndex = 3;	//field 3 is the interface ID
	}
	
	
	string cmdString = "snmpwalk -v1 -c " + community + " " + target + " 1.3.6.1.2.1.4.20.1.2";
	
	char *cmd = new char[cmdString.size()+1];
	cmd[cmdString.size()]=0;
	memcpy(cmd,cmdString.c_str(),cmdString.size());
	
    string walkResult = exec(cmd);
	string ip = "";
	vector<string> addresses;
    vector<string> outputLines;
	vector<string> outputFields;
	
	outputLines = split(walkResult, "\n");
	for (int i=0; i<outputLines.size(); i++)
	{
		outputFields = split(outputLines[i], " ");
		if (fIndex == 0 && outputFields[fIndex].size() > 1)
		{
			ip = outputFields[0].substr(23, outputFields[0].size()-1);
			addresses.push_back(ip);
		}
		else if (outputFields[fIndex].size() > 1)
		{
			addresses.push_back(outputFields[fIndex]);
		}
	}
	
	return addresses;
}

vector<string> snmp::getMasks(string target, string community)
{

}

vector<string> snmp::getInterfaces(string target, string community)
{

}

vector<string> snmp::getSpeeds(string target, string community)
{

}



#endif
