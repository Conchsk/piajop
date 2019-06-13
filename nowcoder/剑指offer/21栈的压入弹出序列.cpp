#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> temp;
        for (int i = 0, j = 0; i < pushV.size(); ++i)
        {
            temp.push(pushV[i]);
            while (!temp.empty() && temp.top() == popV[j])
            {
                temp.pop();
                j++;
            }
        }
        return temp.empty() ? true : false;
    }
};
