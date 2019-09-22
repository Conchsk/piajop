// link https://leetcode-cn.com/problems/pascals-triangle-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int helper(string &str)
    {
        int count[26];
        for (int i = 0; i < 26; ++i)
            count[i] = 0;
        for (auto it = str.begin(); it != str.end(); ++it)
            ++count[*it - 'a'];
        for (int i = 0; i < 26; ++i)
            if (count[i] != 0)
                return count[i];
        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> ret;
        if (queries.size() == 0)
            return ret;
        else
        {
            int count[12];
            for (int i = 0; i < 12; ++i)
                count[i] = 0;
            for (auto it = words.begin(); it != words.end(); ++it)
                ++count[helper(*it)];
            for (int i = 9; i >= 0; --i)
                count[i] += count[i + 1];
            for (auto it = queries.begin(); it != queries.end(); ++it)
                ret.push_back(count[helper(*it) + 1]);
            return ret;
        }
    }
};

int main(void)
{
    vector<string> queries{"bbb", "cc"};
    vector<string> words{"sss"};
    auto result = Solution().numSmallerByFrequency(queries, words);
    for (auto it = result.begin(); it != result.end(); ++it)
        cout << *it << endl;
    return 0;
}
