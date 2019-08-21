// link https://leetcode-cn.com/problems/isomorphic-strings/
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, int> m1, m2;
        for (int i = 0; i < s.length(); ++i)
        {
            if (m1.count(s[i]) == 0)
                m1[s[i]] = t[i] - s[i];
            else if (t[i] - s[i] != m1[s[i]])
                return false;
            if (m2.count(t[i]) == 0)
                m2[t[i]] = t[i] - s[i];
            else if (t[i] - s[i] != m2[t[i]])
                return false;
        }
        return true;
    }
};
