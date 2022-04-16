#include <iostream>

using namespace std;



int main()
{
    int x = 0,*y;
    y = test(&x);
    cout<<y;
    return 0;
}

int *test(int *a)
{
    int *t;
    int *a=99;
    t = a;
    return t;
}
