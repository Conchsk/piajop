#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        string s(str, length);
        int next_index;
        while ((next_index = s.find(" ")) != s.npos)
            s.replace(next_index, 1, "%20");
        s.copy(str, s.size());
    }
};
