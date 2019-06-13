#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    bool match(char *str, char *pattern)
    {
        if (!strlen(pattern))
            return strlen(str) ? false : true;
        if (pattern[1] == '*')
        {
            for (int i = 0; i <= strlen(str); ++i)
            {
                if (i && (str[i - 1] != pattern[0] && pattern[0] != '.'))
                    break;
                if (match(str + i, pattern + 2))
                    return true;
            }
            return false;
        }
        else if (str[0] == pattern[0] || pattern[0] == '.')
            return strlen(str) > 0 ? match(str + 1, pattern + 1) : false;
        else
            return false;
    }
};