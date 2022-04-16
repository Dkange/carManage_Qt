#include <iostream>
#include "test.h"
using namespace std;

int main()
{
    test t1(5);
    test t2(t1);

    t1.dis();
    cout<<"\n=================\n";
    t2.dis();
    return 0;
}
