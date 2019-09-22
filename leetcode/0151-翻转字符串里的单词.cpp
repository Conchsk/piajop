// link https://leetcode-cn.com/problems/reverse-words-in-a-string/
#include <iostream>
using namespace std;

class Solution
{
public:
    void helper(string &s, int start, int end)
    {
        for (int i = 0; i < (end - start) / 2; ++i)
            swap(s[start + i], s[end - 1 - i]);
    }

    string reverseWords(string s)
    {
        // reverse whole string and than reverse each word
        helper(s, 0, s.length());
        int start = 0;
        while (true)
        {
            while (start < s.length() && s[start] == ' ')
                s.erase(start, 1);
            if (start >= s.length())
                break;
            int end = start;
            while (end < s.length() && s[end] != ' ')
                ++end;
            helper(s, start, end);
            start = end + 1;
        }
        if (s.back() == ' ')
            s.pop_back();
        return s;
    }
};
