#include <iostream>
#include <regex>
using namespace std;

class Solution
{
public:
    int StrToInt(string str)
    {
        if (regex_match(str, regex("[+|-]?\\d+")))
            return 1;
        else
            return 0;
    }
};