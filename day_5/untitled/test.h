#ifndef TEST_H
#define TEST_H

#include<iostream>
using namespace std;
class test
{
public:
    test(int i);

    test(test t)
    {
        this->_n = t._n;
    }

    void dis();
private:
    int _n;
};

#endif // TEST_H
