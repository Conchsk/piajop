/**
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 * 如果当前字符流没有存在出现一次的字符，返回#字符。如果当前字符流没有存在出现一次的字符，返回#字符。
 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class Solution
{
public:
    bool firstUse = true;
    int temp[256];
    queue<char> q;

    void Insert(char ch)
    {
        if (firstUse)
        {
            memset(temp, 0, sizeof(temp));
            firstUse = false;
        }
        if (temp[ch] == 0)
            q.push(ch);
        ++temp[ch];
    }

    char FirstAppearingOnce()
    {
        while (!q.empty() && temp[q.front()] != 1)
            q.pop();
        return q.empty() ? '#' : q.front();
    }
};