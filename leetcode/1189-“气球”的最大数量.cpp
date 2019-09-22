// link https://leetcode-cn.com/problems/maximum-number-of-balloons/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int b, a, l, o, n;
        b = a = l = o = n = 0;
        for (auto it = text.begin(); it != text.end(); ++it)
        {
            switch (*it)
            {
            case 'b':
                ++b;
                break;
            case 'a':
                ++a;
                break;
            case 'l':
                ++l;
                break;
            case 'o':
                ++o;
                break;
            case 'n':
                ++n;
                break;
            default:
                break;
            }
        }
        l /= 2;
        o /= 2;
        return min(b, min(a, min(l, min(o, n))));
    }
};
