#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        int pos['z' - 'A' + 1];
        int count['z' - 'A' + 1];
        memset(pos, -1, sizeof(pos));
        memset(count, 0, sizeof(count));
        for (int i = 0; i < str.length(); ++i)
        {
            int index = str[i] - 'A';
            if (pos[index] == -1)
                pos[index] = i;
            ++count[index];
        }
        int ret = 0x3f3f3f3f;
        for (int i = 0; i < 'z' - 'A' + 1; ++i)
            if (count[i] == 1 && pos[i] < ret)
                ret = pos[i];
        return ret == 0x3f3f3f3f ? -1 : ret;
    }
};