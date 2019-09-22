// link https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> myStack;
        queue<char> myQueue;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (*it != ')')
                myStack.push(*it);
            else
            {
                while (myStack.top() != '(')
                {
                    myQueue.push(myStack.top());
                    myStack.pop();
                }
                myStack.pop();
                while (!myQueue.empty())
                {
                    myStack.push(myQueue.front());
                    myQueue.pop();
                }
            }
        }
        string ret;
        while (!myStack.empty())
        {
            ret.insert(ret.begin(), myStack.top());
            myStack.pop();
        }
        return ret;
    }
};
