#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        map<int, int> _map;
        for (auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            auto _found = _map.find(*it);
            if (_found == _map.end())
                _map.insert(pair<int, int>(*it, 1));
            else
                _map[*it] = (*_found).second + 1;
            if (_map[*it] > numbers.size() / 2)
                return *it;
        }
        return 0;
    }
};