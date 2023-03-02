#include<iostream>

using namespace std;

int main()
{
    int i = 10;
    cout<<&i<<endl;

    int *p = &i;
    cout<<p<<endl;
    cout<<*p<<endl;

    cout<<sizeof(p)<<endl;
    cout<<i<<endl;
    cout<<*p<<endl;

    i++;

    cout<<i<<endl;
    cout<<*p<<endl;

    int a = i;  // can also right *p
    a++;

    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<a<<endl;

    i = 12;

    cout<<i<<endl;
    cout<<*p<<endl;

    *p = 23;

    cout<<i<<endl;
    cout<<*p<<endl;

    (*p)++;

    cout<<i<<endl;
    cout<<*p<<endl;

    // float f = 10.2;
    // float *fp = &f;

    // double d = 122.32;
    // double *pd = &d;

    // Should not do something like this
    // Put int *p = 0;

    // int *p;

    // cout<<p<<endl;

    // cout<<*p<<endl;

    // (*p)++;

    // cout<<*p<<endl;
}