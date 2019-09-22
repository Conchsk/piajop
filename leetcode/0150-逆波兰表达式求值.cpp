// link https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        int p1, p2;
        for (auto it = tokens.begin(); it != tokens.end(); ++it)
        {
            if (*it == "+")
            {
                p1 = s.top();
                s.pop();
                p2 = s.top();
                s.pop();
                s.push(p2 + p1);
            }
            else if (*it == "-")
            {
                p1 = s.top();
                s.pop();
                p2 = s.top();
                s.pop();
                s.push(p2 - p1);
            }
            else if (*it == "*")
            {
                p1 = s.top();
                s.pop();
                p2 = s.top();
                s.pop();
                s.push(p2 * p1);
            }
            else if (*it == "/")
            {
                p1 = s.top();
                s.pop();
                p2 = s.top();
                s.pop();
                s.push(p2 / p1);
            }
            else
                s.push(atoi(it->c_str()));
        }
        return s.top();
    }
};
