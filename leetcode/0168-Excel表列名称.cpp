// link https://leetcode-cn.com/problems/excel-sheet-column-title/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string convertToTitle(int n)
    {
        string ret;
        for (int i = n; i > 0; i = (i - 1) / 26)
            ret.insert(ret.begin(), i % 26 ? 'A' - 1 + i % 26 : 'Z');
        return ret;
    }
};
