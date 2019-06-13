#include <iostream>
using namespace std;

class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        int cursor2 = 0;
        int cursor3 = 0;
        int cursor5 = 0;

        int *uglyNumber = new int[index];
        uglyNumber[0] = 1;
        for (int i = 1; i < index; ++i)
        {
            int tun2 = uglyNumber[cursor2] * 2;
            int tun3 = uglyNumber[cursor3] * 3;
            int tun5 = uglyNumber[cursor5] * 5;
            int nextUglyNumber = min(tun2, min(tun3, tun5));
            uglyNumber[i] = nextUglyNumber;
            if (tun2 == nextUglyNumber)
                cursor2++;
            if (tun3 == nextUglyNumber)
                cursor3++;
            if (tun5 == nextUglyNumber)
                cursor5++;
        }

        int ret = uglyNumber[index - 1];
        delete[] uglyNumber;
        return ret;
    }
};

int main(void)
{
    Solution su;
    cout << su.GetUglyNumber_Solution(100) << endl;
    return 0;
}
