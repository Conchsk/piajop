// link https://leetcode-cn.com/problems/minimum-window-subsequence/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string minWindow(string S, string T)
    {
        int minLength = S.length();
        int minIndex = -1;
        for (int i = 0; i < S.length(); ++i)
        {
            if (S[i] == T[0])
            {
                int tempI = i + 1;
                bool flag = true;
                for (int j = 1; j < T.length(); ++j)
                {
                    while (tempI < S.length() && S[tempI] != T[j])
                        ++tempI;
                    ++tempI;
                    if (tempI > S.length())
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag && minLength > tempI - i)
                {
                    minLength = tempI - i;
                    minIndex = i;
                }
            }
        }
        return minIndex == -1 ? string("") : S.substr(minIndex, minLength);
    }
};
