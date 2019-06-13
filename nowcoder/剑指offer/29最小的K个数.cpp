#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        if (input.size() < k)
            return vector<int>();
        vector<int> _heap(k + 1, 0x3f3f3f3f);
        make_heap(_heap.begin(), _heap.end());
        for (auto it = input.begin(); it != input.end(); ++it)
        {
            _heap[k] = *it;
            push_heap(_heap.begin(), _heap.end());
            pop_heap(_heap.begin(), _heap.end());
        }
        _heap.pop_back();
        sort_heap(_heap.begin(), _heap.end());
        return _heap;
    }
};