#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int ret = 0;
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (*it < k)
                continue;
            else if (*it == k)
                ret++;
            else
                break;
        }
        return ret;
    }
};