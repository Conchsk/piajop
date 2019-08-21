// link https://leetcode-cn.com/problems/read-n-characters-given-read4/

#include <iostream>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int point = 0;
        int count = 0;
        while (point < n && (count = read4(buf + point)) != 0)
            point += count;
        return min(point, n);
    }
};
