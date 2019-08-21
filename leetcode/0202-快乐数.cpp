// link https://leetcode-cn.com/problems/happy-number/
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int ret = 0;
        while (n)
        {
            ret += (n % 10) * (n % 10);
            n /= 10;
        }
        cout << ret << endl;
        if (ret == 1 || ret == 7)
            return true;
        else if (ret < 10)
            return false;
        else
            return isHappy(ret);
    }
};
