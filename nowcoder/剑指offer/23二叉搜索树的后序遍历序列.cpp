#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        return sequence.size() == 0 ? false : helper(sequence, 0, sequence.size() - 1);
    }

    bool helper(vector<int> sequence, int start, int end)
    {
        if (end - start < 2)
            return true;
        for (int i = start; i < end; ++i)
            if (sequence[i] > sequence[end])
            {
                for (int j = i; j < end; ++j)
                    if (sequence[j] < sequence[end])
                        return false;
                return helper(sequence, start, i - 1) && helper(sequence, i, end - 1);
            }
        return helper(sequence, start, end - 1);
    }
};
