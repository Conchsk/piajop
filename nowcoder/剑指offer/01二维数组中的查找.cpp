#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        int cols = array[0].size();
        int rows = array.size();

        int x, y;
        x = 0;
        y = cols - 1;
        while (x < rows && y >= 0)
        {
            if (array[x][y] == target)
                return true;
            else if (array[x][y] > target)
                --y;
            else
                ++x;
        }
        return false;
    }
};