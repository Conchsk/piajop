// link https://leetcode-cn.com/problems/add-strings/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string ret;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            if (i >= 0)
                carry += num1[i--] - '0';
            if (j >= 0)
                carry += num2[j--] - '0';
            ret.insert(ret.begin(), carry % 10 + '0');
            carry /= 10;
        }
        if (carry != 0)
            ret.insert(ret.begin(), '1');
        return ret;
    }
};
