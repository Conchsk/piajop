/**
 * 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        if (str.empty())
            return str;
        if (n < 0)
            n = -n;
        n %= str.length();
        if (n < 0)
            n = str.length() - n;

        for (auto it = str.begin();; ++it)
            if (!n--)
            {
                reverse(str.begin(), it);
                reverse(it, str.end());
                reverse(str.begin(), str.end());
                break;
            }

        return str;
    }
};