#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    stack<int> datStack;
    stack<int> minStack;

    void push(int value)
    {
        if (minStack.empty() || minStack.top() >= value)
            minStack.push(value);
        datStack.push(value);
    }

    void pop()
    {
        if (minStack.top() == datStack.top())
            minStack.pop();
        datStack.pop();
    }

    int top()
    {
        return datStack.top();
    }

    int min()
    {
        return minStack.top();
    }
};
