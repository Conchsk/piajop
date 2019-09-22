// link https://leetcode-cn.com/problems/shortest-word-distance/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int shortestDistance(vector<string> &words, string word1, string word2)
    {
        int minDist = 0x3f3f3f3f;
        int word1Pos = -1;
        int word2Pos = -1;
        for (auto it = words.begin(); it != words.end(); ++it)
        {
            if (*it == word1)
                word1Pos = it - words.begin();
            else if (*it == word2)
                word2Pos = it - words.begin();
            if (word1Pos != -1 && word2Pos != -1 && minDist > abs(word1Pos - word2Pos))
                minDist = abs(word1Pos - word2Pos);
        }
        return minDist;
    }
};
