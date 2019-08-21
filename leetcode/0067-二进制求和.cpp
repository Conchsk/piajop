// link https://leetcode-cn.com/problems/add-binary/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int bufferSize = a.length() > b.length() ? a.length() + 2 : b.length() + 2;
        char buffer[bufferSize];
        buffer[0] = '0';
        buffer[bufferSize - 1] = '\0';
        int carry = 0;
        for (int i = 1; i < bufferSize; ++i)
        {
            if (i <= a.length())
                carry += a[a.length() - i] - '0';
            if (i <= b.length())
                carry += b[b.length() - i] - '0';
            buffer[bufferSize - i - 1] = carry % 2 + '0';
            carry /= 2;
        }
        if (buffer[0] == '0')
            return string(buffer + 1);
        else
            return string(buffer);
    }
};
