// link https://leetcode-cn.com/problems/length-of-last-word/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        int cursor = s.length() - 1;
        while (cursor >= 0 && s[cursor] == ' ')
            --cursor;
        while (cursor >= 0 && s[cursor] != ' ')
        {
            --cursor;
            ++length;
        }
        return length;
    }
};
