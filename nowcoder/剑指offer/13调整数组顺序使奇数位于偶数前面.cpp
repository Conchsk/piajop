#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        for (int i = 1; i < array.size(); ++i)
            for (int j = 0; j < array.size() - i; ++j)
                if ((array[j] & 1) == 0 && (array[j + 1] & 1) == 1)
                    swap(array[j], array[j + 1]);
    }
};
