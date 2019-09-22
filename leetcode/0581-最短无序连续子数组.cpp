// link https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        stack<int> myStack;

        int left = nums.size();
        myStack.push(0);
        for (int i = 1; i < nums.size(); ++i)
        {
            while (!myStack.empty() && nums[i] < nums[myStack.top()])
            {
                left = min(left, myStack.top());
                myStack.pop();
            }
            myStack.push(i);
        }
        if (left == nums.size())
            return 0;

        while (!myStack.empty())
            myStack.pop();
        int right = 0;
        myStack.push(nums.size() - 1);
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            while (!myStack.empty() && nums[i] > nums[myStack.top()])
            {
                right = max(right, myStack.top());
                myStack.pop();
            }
            myStack.push(i);
        }
        return right - left + 1;
    }
};
