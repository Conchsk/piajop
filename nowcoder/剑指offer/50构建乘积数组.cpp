/**
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> ret(A.size());
        int temp = 1;
        for (int i = 0; i < A.size(); ++i)
        {
            ret[i] = temp;
            temp *= A[i];
        }
        temp = 1;
        for (int i = A.size() - 1; i >= 0; --i)
        {
            ret[i] *= temp;
            temp *= A[i];
        }
        return ret;
    }
};