#ifndef STRINGMANIP_HPP
#define STRINGMANIP_HPP

#include<string>
#include<vector>

using namespace std;

vector<string> split(string data, string delim)
{
        vector<string> result;
        string holder = "";

        bool done = false;

        while(!done)
        {
                size_t loc = data.find(delim);
                if (loc > data.size())
                {
                        holder = data;
                        result.push_back(holder);
                        done = true;
                        break;
                }
                holder = data.substr(0, loc);
                data = data.substr(loc+1, data.size());
                result.push_back(holder);
        }
        return result;
}

#endif
