// link https://leetcode-cn.com/problems/knight-probability-in-chessboard/
#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    inline bool helper(int N, int r, int c)
    {
        return r >= 0 && r < N && c >= 0 && c < N;
    }

    double knightProbability(int N, int K, int r, int c)
    {
        double dp[2][25][25];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dp[0][i][j] = 1.0;
        int last = 0;
        int current = 1;
        int rAdd[]{-2, -1, 1, 2, 2, 1, -1, -2};
        int cAdd[]{1, 2, 2, 1, -1, -2, -2, -1};
        while (K--)
        {
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                {
                    dp[current][i][j] = 0.0;
                    for (int k = 0; k < 8; ++k)
                        if (helper(N, i + rAdd[k], j + cAdd[k]))
                            dp[current][i][j] += dp[last][i + rAdd[k]][j + cAdd[k]];
                    dp[current][i][j] /= 8.0;
                }
            swap(last, current);
        }
        return dp[last][r][c];
    }
};
