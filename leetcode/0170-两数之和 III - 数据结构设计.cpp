// link https://leetcode-cn.com/problems/two-sum-iii-data-structure-design/
#include <iostream>
#include <map>
using namespace std;

class TwoSum
{
public:
    map<int, int> ds;

    /** Initialize your data structure here. */
    TwoSum()
    {
    }

    /** Add the number to an internal data structure.. */
    void add(int number)
    {
        if (ds.count(number) == 0)
            ds[number] = 1;
        else
            ds[number] = 2;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value)
    {
        for (auto it = ds.begin(); it != ds.end(); ++it)
        {
            if (it->first * 2 == value)
                return ds[it->first] == 2;
            else if (ds.count(value - it->first))
                return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
