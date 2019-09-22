// link https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {
        int allSum = 0;
        for (int i = 0; i < A.size(); ++i)
            allSum += A[i];
        if (allSum % 3 != 0)
            return false;
        int i = 0;
        for (int part = 0; part < 3 - 1; ++part)
        {
            int tmpSum = A[i++];
            while (i < A.size() && tmpSum * 3 != allSum)
                tmpSum += A[i++];
            if (i == A.size())
                return false;
        }
        return true;
    }
};
