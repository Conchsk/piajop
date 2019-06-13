#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string> ret;
        if (str.size() == 0)
            return ret;        
        char *cstr = new char[str.size()];
        str.copy(cstr, str.size());
        sort(cstr, cstr + str.size());
        do
            ret.push_back(string(cstr, str.size()));
        while (next_permutation(cstr, cstr + str.size()));
        delete[] cstr;
        return ret;
    }
};