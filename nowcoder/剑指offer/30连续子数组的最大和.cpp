#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ret = -0x3f3f3f3f;
        int sum = 0;
        for (auto it = array.begin(); it != array.end(); ++it)
        {
            sum += *it;
            if (ret < sum)
                ret = sum;
            if (sum < 0)
                sum = 0;
        }
        return ret;
    }
};