// link https://leetcode-cn.com/problems/print-in-order/
#include <iostream>
#include <functional>
#include <mutex>
using namespace std;

class Foo
{
public:
    mutex m1;
    mutex m2;

    Foo()
    {
        m1.lock();
        m2.lock();
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond)
    {
        unique_lock<mutex> l(m1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m2.unlock();
    }

    void third(function<void()> printThird)
    {
        unique_lock<mutex> l(m2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
