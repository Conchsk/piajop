#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end(), Solution::cmp);
        stringstream sstream;
        for (auto it = numbers.begin(); it != numbers.end(); ++it)
            sstream << *it;
        return sstream.str();
    }

    static bool cmp(int a, int b)
    {
        stringstream sstream;
        sstream << a << b;
        string ab = sstream.str();
        sstream.str("");
        sstream << b << a;
        string ba = sstream.str();
        return ab < ba;
    }
};